#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "tablaDeSimbolos.h"
#include "funciones.h"


// Función para mostrar la lista de variables.
void mostrarListaVariables (struct nodoVariableTS* puntero) {

    struct nodoVariableTS* aux = puntero;

	printf("\n\n-----------------------------------------------------------------------------\n");
	printf("Lista de Variables de TS: \n");
	printf("-----------------------------------------------------------------------------\n");

    if(puntero != NULL) {

		printf("TIPO\t\tIDENTIFICADOR\n\n");

        while(aux!=NULL) {

			printf("%s\t\t%s\t\t\t%d\n", aux->idVariable, aux->tipo);

            aux=aux->nextVariable;
        }
	}
}

// Función para mostrar la lista de funciones.
void mostrarListaFunciones (struct nodoFuncionTS* puntero) {

    struct nodoFuncionTS* aux = puntero;

    printf("\n\n-----------------------------------------------------------------------------\n");
    printf("Lista de Funciones de TS: \n");
    printf("-----------------------------------------------------------------------------\n");

    if(puntero!=NULL) {

        printf("TIPO\t\tIDENTIFICADOR\n\n");

        while(aux != NULL) {
            printf("%s\t\t%s\n", aux->idFuncion, aux->tipo);

            aux = aux->nextFuncion;
        }
    }

    free(aux);
}

// Función para mostrar la lista de Errores Lexicos.
void mostrarListaErrores (struct nodoErrores* puntero, char* tipoError) {

    struct nodoErrores* aux = puntero;

    printf("\n\n-----------------------------------------------------------------------------\n");
    printf("Errores %s: \n", tipoError);
    printf("-----------------------------------------------------------------------------\n");

    if(puntero!=NULL) {

        while(aux != NULL) {
            printf("\n%s\n\n", aux->comentario);

            aux = aux->nextError;
        }
    }

    free(aux);
}
