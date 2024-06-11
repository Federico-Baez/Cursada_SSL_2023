#ifndef TS_H
#define TS_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char mensajeError[100];
struct nodoErrores* ListaDeErroresSemanticos = NULL;


struct nodoErrores* agregarError(struct nodoErrores* puntero, char* error);
struct nodoVariableTS* extraerVariableTS (struct nodoVariableTS* ListaDeclaracionesDeVariables, char* idVariableABuscar);

struct nodoVariableTS {
    char* tipo;
    char* idVariable;
    struct nodoVariableTS* nextVariable;
};

struct nodoParametroTS {
    char* tipo;
    char* idParametro;
    struct nodoParametroTS* nextParametro;
};

struct nodoFuncionTS {
    char* tipo;
    char* idFuncion;
    struct nodoParametroTS* ListaParametros;
    struct nodoFuncionTS* nextFuncion;
};

struct nodoParametrosInvocacionTS {
    char* idParametroInvocacion;
    struct nodoParametrosInvocacionTS* nextParametroInvocacion;
};
struct nodoErrores {
    char comentario[100];
    struct nodoErrores* nextError;
};


// Función para agregar una declaración a la lista de declaraciones.
struct nodoVariableTS* agregarVariableTS (struct nodoVariableTS* puntero, char* nuevoIdVariable, char* nuevoTipo) {

	// Crea un nuevo nodo de declaración.
	struct nodoVariableTS* nuevo;

	nuevo = (struct nodoVariableTS*) malloc(sizeof(struct nodoVariableTS));

	char* nuevoID, *nuevoTIPO;

	nuevoID = (char*) malloc(sizeof(char[30]));
	nuevoTIPO = (char* ) malloc(sizeof(char[30]));

	strcpy(nuevoID,nuevoIdVariable);
	strcpy(nuevoTIPO,nuevoTipo);

	nuevo->idVariable = nuevoID;
	nuevo->tipo = nuevoTIPO;
	nuevo->nextVariable = NULL;

	// Agrega el nuevo nodo a la lista de declaraciones.
	if(puntero != NULL) {

        struct nodoVariableTS* aux = puntero;

        while(aux->nextVariable != NULL){

            aux = aux->nextVariable;

        }

        aux->nextVariable = nuevo;

    } else {

        puntero = nuevo;

    }

    return puntero;
}

// Función para agregar un parámetro a la lista de árametros.
struct nodoParametroTS* agregarParametroTS (struct nodoParametroTS* puntero, char* nuevoIdVariable, char* nuevoTipo) {

	// Crea un nuevo nodo de declaración.
	struct nodoParametroTS* nuevo;

	nuevo = (struct nodoParametroTS*) malloc(sizeof(struct nodoParametroTS));

	char* nuevoID, *nuevoTIPO, *nuevoVALOR;

	nuevoID = (char*) malloc(sizeof(char[30]));
	nuevoTIPO = (char* ) malloc(sizeof(char[30]));

	strcpy(nuevoID,nuevoIdVariable);
	strcpy(nuevoTIPO,nuevoTipo);

	nuevo->idParametro = nuevoID;
	nuevo->tipo = nuevoTIPO;
	nuevo->nextParametro = NULL;

	// Agrega el nuevo nodo a la lista de declaraciones.
	if(puntero != NULL) {

        struct nodoParametroTS* aux = puntero;

        while(aux->nextParametro != NULL){

            aux = aux->nextParametro;

        }

        aux->nextParametro = nuevo;

    } else {

        puntero = nuevo;

    }

    return puntero;
}

// Función para agregar y manejar los parámetros de las invocaciones de funciones.
struct nodoParametrosInvocacionTS* agregarParametroInvocacion(struct nodoParametrosInvocacionTS* puntero, char* nuevoIdParametroInvocacion) {
    // Crea un nuevo nodo de parámetro de invocación.
    struct nodoParametrosInvocacionTS* nuevo;

    nuevo = (struct nodoParametrosInvocacionTS*) malloc(sizeof(struct nodoParametrosInvocacionTS));

    char* nuevoID = (char*) malloc(sizeof(char[30]));

    strcpy(nuevoID, nuevoIdParametroInvocacion);

    nuevo->idParametroInvocacion = nuevoID;
    nuevo->nextParametroInvocacion = NULL;

    // Agrega el nuevo nodo a la lista de parámetros de invocación.
    if(puntero != NULL) {
        struct nodoParametrosInvocacionTS* aux = puntero;

        while(aux->nextParametroInvocacion != NULL){
            aux = aux->nextParametroInvocacion;
        }

        aux->nextParametroInvocacion = nuevo;
    } else {
        puntero = nuevo;
    }

    return puntero;
}

struct nodoFuncionTS* agregarFuncionTS (struct nodoFuncionTS* puntero, char* nuevoId,char* nuevoTipo,  struct nodoParametroTS* nuevaListaParametros) {
	// Crea un nuevo nodo de función.
	struct nodoFuncionTS* nuevo;
    struct nodoParametroTS* nuevaListaDeParametros;

	nuevo = (struct nodoFuncionTS*)malloc(sizeof(struct nodoFuncionTS));
    nuevaListaDeParametros = (struct nodoParametroTS*)malloc(sizeof(struct nodoParametroTS));

	char* nuevoID,*nuevoTIPO;

	nuevoID = (char*)malloc(sizeof(char*));
	nuevoTIPO = (char*)malloc(sizeof(char*));

	strcpy(nuevoID,nuevoId);
	strcpy(nuevoTIPO,nuevoTipo);

    nuevaListaDeParametros = nuevaListaParametros;

	nuevo->idFuncion = nuevoID;
	nuevo->tipo = nuevoTIPO;
	nuevo->ListaParametros = nuevaListaDeParametros;
	nuevo->nextFuncion = NULL;

	// Agrega el nuevo nodo a la lista de funciones.
	if(puntero != NULL) {

        struct nodoFuncionTS* aux = puntero;

        while(aux->nextFuncion != NULL) {

            aux = aux->nextFuncion;

        }

        aux->nextFuncion = nuevo;

    } else {

        puntero = nuevo;

    }

    return puntero;
}


struct nodoErrores* agregarError(struct nodoErrores* puntero, char* error) {
    // Crea un nuevo nodo de función.
	struct nodoErrores* nuevo;

	nuevo = (struct nodoErrores*)malloc(sizeof(struct nodoErrores));

	char* nuevoError;

	nuevoError = (char*)malloc(sizeof(char*));

	strcpy(nuevo->comentario,error);
	nuevo->nextError = NULL;

	// Agrega el nuevo nodo a la lista de funciones.
	if(puntero != NULL) {

        struct nodoErrores* aux = puntero;

        while(aux->nextError != NULL) {

            aux = aux->nextError;

        }

        aux->nextError = nuevo;

    } else {

        puntero = nuevo;

    }

    return puntero;
}

struct nodoVariableTS* validarDobleDeclaracionDeVariables(struct nodoVariableTS* puntero, char* nuevoIdVariable, char* nuevoTipo) {
    struct nodoVariableTS* aux = puntero;
    // Recorre la lista enlazada de variables
    while (aux != NULL) {
        // Comprueba si el nuevo identificador de variable ya existe en la lista
        if (strcmp(aux->idVariable, nuevoIdVariable) == 0) {
            sprintf(mensajeError, "La variable '%s' ya ha sido anteriormente declarada.", nuevoIdVariable);
            ListaDeErroresSemanticos = agregarError(ListaDeErroresSemanticos, mensajeError);

            return puntero;
        }
        aux = aux->nextVariable;
    }
    // Si no se encontró un repetido del id, crea una nueva variable y agrega al final de la lista
    return agregarVariableTS(puntero, nuevoIdVariable, nuevoTipo);
}


struct nodoFuncionTS* validarDobleDeclaracionDeFunciones(struct nodoFuncionTS* puntero, char* nuevoIdFuncion, char* nuevoTipo,struct nodoParametroTS* nuevaListaParametros) {
    struct nodoFuncionTS* aux = puntero;
    
    // Recorre la lista enlazada de funciones
    while (aux != NULL) {

        // Comprueba si el nuevo identificador de función ya existe en la lista
        if(strcmp(aux->idFuncion, nuevoIdFuncion) == 0) {
            sprintf(mensajeError, "La funcion '%s' ya ha sido anteriormente declarada.\n", nuevoIdFuncion);
            ListaDeErroresSemanticos = agregarError(ListaDeErroresSemanticos, mensajeError);

            return puntero;
        }
        aux = aux->nextFuncion;
    }

    // Si no se encontró un repetido del id, crea una nueva función y agrega al final de la lista
    return agregarFuncionTS(puntero, nuevoIdFuncion, nuevoTipo, nuevaListaParametros);

} 

int validarCantidadParametros(struct nodoFuncionTS* funcion1, struct nodoParametroTS* ListaParametrosAComparar) {
    int flag = -1;
    int cantidadParametrosFuncion1 = contarParametros(funcion1->ListaParametros), cantidadParametrosFuncion2 = contarParametros(ListaParametrosAComparar);

    if( cantidadParametrosFuncion1 == cantidadParametrosFuncion2) {
        flag = 0;
    }

    return flag;
}

bool validarTipoParametros(struct nodoFuncionTS* funcion1, struct nodoParametroTS* ListaParametrosAComparar) {
    bool flag = false;
    int cantParamIguales = 0;

    struct nodoParametroTS* aux1 = funcion1->ListaParametros, *aux2 = ListaParametrosAComparar;

    while (aux1 != NULL && aux2 != NULL)
    {
        if ( strcmp(aux1->tipo,aux2->tipo) == 0 )
        {
            cantParamIguales++;
        }
        
        aux1 = aux1->nextParametro;
        aux2 = aux2->nextParametro;
    }

    if ( cantParamIguales == contarParametros(funcion1->ListaParametros) ) {
        flag = true;
    }

    return flag;
}

int contarParametros(struct nodoParametroTS* ListaParametros) {
    struct nodoParametroTS* aux = ListaParametros;
    int contador = 0;

    while ( aux != NULL)
    {
        contador++;
        aux = aux->nextParametro;
    }

    free(aux);

    return contador;
}

struct nodoFuncionTS* extraerNodoFuncion(struct nodoFuncionTS* ListaDeclaracionesDeFunciones, char* idFuncionABuscar) {
    struct nodoFuncionTS* aux = ListaDeclaracionesDeFunciones;

    // Recorre la lista enlazada de funciones
    while (aux != NULL) {
        // Comprueba si el nuevo identificador de función ya existe en la lista
        if( strcmp(aux->idFuncion, idFuncionABuscar) == 0 ) {
            return aux;
        }
        aux = aux->nextFuncion;
    }

    return NULL;
}

char* obtenerTipo(struct nodoVariableTS* ListaDeclaracionesDeVariables, char* variable) {
    struct nodoVariableTS* aux =  extraerVariableTS(ListaDeclaracionesDeVariables,variable);

    if( aux == NULL ) {
        return NULL;
    } 
    else {
        return aux->tipo;
    }
}

void validacionDeTiposEnOperacionesBinarias (struct nodoVariableTS* ListaDeclaracionesDeVariables, char* variable1, char* variable2, int linea) {
    
    char *tipo1, *tipo2;

    tipo1 =  obtenerTipo(ListaDeclaracionesDeVariables, variable1);
    tipo2 =  obtenerTipo(ListaDeclaracionesDeVariables, variable2);

    if( tipo1 == NULL || tipo2 == NULL ){
        sprintf(mensajeError, "No existe alguno de los identificadores en la linea %d", linea);
        ListaDeErroresSemanticos = agregarError(ListaDeErroresSemanticos, mensajeError);
    } 
    else {
        if( ((strcmp(tipo1,"int") == 0 || strcmp(tipo1,"float") == 0  || strcmp(tipo1,"char") == 0 ) && ( strcmp(tipo2,"int") == 0 || strcmp(tipo2,"float") == 0  || strcmp(tipo2,"char") == 0 )) == false ) {
            sprintf(mensajeError, "Validacion de tipos incorrecta en la linea %d", linea);
            ListaDeErroresSemanticos = agregarError(ListaDeErroresSemanticos, mensajeError);
        }
    }
}

struct nodoVariableTS* extraerVariableTS (struct nodoVariableTS* ListaDeclaracionesDeVariables, char* idVariableABuscar) {
    struct nodoVariableTS* aux = ListaDeclaracionesDeVariables;

    // Recorre la lista enlazada de funciones
    while (aux != NULL) {
        // Comprueba si el nuevo identificador de función ya existe en la lista
        if( strcmp(aux->idVariable, idVariableABuscar) == 0 ) {
            return aux;
        }
        aux = aux->nextVariable;
    }

    return NULL;
}

struct nodoParametroTS* buscarParametros(struct nodoVariableTS* ListaDeclaracionesDeVariables, struct nodoParametrosInvocacionTS* ListaDeParametrosSinTipo) {
    struct nodoParametroTS* ListaDeParametrosConTipo = NULL; 
    struct nodoParametrosInvocacionTS* auxParametroInvocacion = ListaDeParametrosSinTipo;

    while ( auxParametroInvocacion != NULL )
    {
        struct nodoVariableTS* auxVariable = extraerVariableTS(ListaDeclaracionesDeVariables, auxParametroInvocacion->idParametroInvocacion);
        
        if ( auxVariable != NULL) {
            ListaDeParametrosConTipo = agregarParametroTS(ListaDeParametrosConTipo, auxVariable->idVariable, auxVariable->tipo);
        }
        else{
            break;
        }

        auxParametroInvocacion = auxParametroInvocacion->nextParametroInvocacion;
    }

    return ListaDeParametrosConTipo;
}

void validarExistenciaParametros(struct nodoVariableTS* ListaDeclaracionesDeVariables, struct nodoParametroTS* ListaParametrosAComparar) {
    struct nodoParametroTS* aux = ListaParametrosAComparar;

    while ( aux != NULL )
    {
        struct nodoVariableTS* auxVariable = extraerVariableTS(ListaDeclaracionesDeVariables, aux->idParametro);
        
        printf("\n\n Validar Existencia de Parametros \n\n");
        if ( auxVariable == NULL) {
            sprintf(mensajeError, "El parametro '%s' no existe \n", auxVariable->idVariable);
            ListaDeErroresSemanticos = agregarError(ListaDeErroresSemanticos, mensajeError);
        }

        aux = aux->nextParametro;
    }

    free(aux);
}

void validacionGeneralDeParametros(struct nodoFuncionTS* ListaDeclaracionesDeFunciones,struct nodoVariableTS* ListaDeclaracionesDeVariables, char* nombreFuncion, struct nodoParametrosInvocacionTS* ListaDeParametrosNombres) {

    struct nodoFuncionTS* auxFuncion = (struct nodoFuncionTS*) malloc(sizeof(struct nodoFuncionTS));
    struct nodoParametroTS* ListaDeParametros = (struct nodoParametroTS*) malloc(sizeof(struct nodoParametroTS*)); 

  
    auxFuncion = extraerNodoFuncion(ListaDeclaracionesDeFunciones,nombreFuncion);
    ListaDeParametros = buscarParametros(ListaDeclaracionesDeVariables, ListaDeParametrosNombres); 
    
    if( auxFuncion == NULL ){
        sprintf(mensajeError, "La funcion '%s' no existe", nombreFuncion);
        ListaDeErroresSemanticos = agregarError(ListaDeErroresSemanticos, mensajeError);
    }
    else{    
        if ( ListaDeParametros != NULL ) { 
            if ( validarCantidadParametros(auxFuncion, ListaDeParametros) == -1) {
                sprintf(mensajeError, "La cantidad de parametros para la funcion '%s' no es la correcta", nombreFuncion);
                ListaDeErroresSemanticos = agregarError(ListaDeErroresSemanticos, mensajeError);
            }
            else {
                if ( validarTipoParametros(auxFuncion, ListaDeParametros) == false )
                {
                    sprintf(mensajeError, "Los tipos de parametros para la funcion '%s' no es la correcta", nombreFuncion);
                    ListaDeErroresSemanticos = agregarError(ListaDeErroresSemanticos, mensajeError);
                }   
            }
        }
    } 

    free(auxFuncion);
    free(ListaDeParametros);
}
 
// Función para mostrar la lista de variables.
void mostrarListaVariables (struct nodoVariableTS* puntero) {

    struct nodoVariableTS* aux = puntero;

	printf("\n\n--------------------------------------------------------------------------------------------\n");
	printf("Lista de Variables de TS: \n");
	printf("--------------------------------------------------------------------------------------------\n");

    if(puntero!=NULL) {

		printf("TIPO\t\tIDENTIFICADOR\n\n");

        while(aux!=NULL) {

			printf("%s\t\t%s\n", aux->tipo, aux->idVariable);

            aux=aux->nextVariable;
        }
	}

    free(aux);
}

// Función para mostrar la lista de funciones.
void mostrarListaFunciones (struct nodoFuncionTS* puntero) {

    struct nodoFuncionTS* aux = puntero;
    

    printf("\n\n--------------------------------------------------------------------------------------------\n");
    printf("Lista de Funciones de TS: \n");
    printf("--------------------------------------------------------------------------------------------\n");

    if(puntero!=NULL) {

        printf("TIPO\t\tIDENTIFICADOR\t\tCANTIDAD_PARAMETROS \t\tTIPOS_PARAMETROS\n\n");

        while(aux!=NULL) {
            struct nodoParametroTS* auxParams = aux->ListaParametros;

            printf("%s\t\t%s\t\t\t%d\t\t\t\t", aux->tipo, aux->idFuncion, contarParametros(auxParams));
            
            while(auxParams!=NULL) {
            if (auxParams->nextParametro != NULL) {
                printf("%s,", auxParams->tipo);
            } else {
                printf("%s", auxParams->tipo);
            }
            auxParams = auxParams->nextParametro;
        }
        printf("\n");

            aux = aux->nextFuncion;
        }
    }

    free(aux);
}

// Función para mostrar la lista de Errores Lexicos.
void mostrarListaErrores (struct nodoErrores* puntero, char* tipoError) {

    struct nodoErrores* aux = puntero;

    printf("\n\n--------------------------------------------------------------------------------------------\n");
    printf("Errores %s: \n", tipoError);
    printf("--------------------------------------------------------------------------------------------\n");

    if(puntero!=NULL) {

        while(aux != NULL) {
            printf("\n%s\n", aux->comentario);

            aux = aux->nextError;
        }
    }

    free(aux);
}

#endif// TS_H