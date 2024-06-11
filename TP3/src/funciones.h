// Incluye las bibliotecas necesarias.
#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Define una estructura de datos para el nodo de declaración.
struct nodoDeclaracion {
    char* id;         // Identificador de la declaración.
    char* tipo;       // Tipo de dato de la declaración.
    int linea;       // Número de línea en la que se encontró la declaración.
    struct nodoDeclaracion* next; // Puntero al siguiente nodo de declaración.
};

// Define una estructura de datos para el nodo de función.
struct nodoFuncion {
    char* id;         // Identificador de la función.
    char* tipo;       // Tipo de dato de retorno de la función.
    int linea;       // Número de línea en la que se encontró la función.
    struct nodoFuncion* next; // Puntero al siguiente nodo de función.
};

// Define una estructura de datos para el nodo de sentencia.
struct nodoSentencia {
    char* tipo;       // Tipo de la sentencia.
    int linea;       // Número de línea en la que se encontró la sentencia.
    struct nodoSentencia* next; // Puntero al siguiente nodo de sentencia.
};

// Función para agregar una declaración a la lista de declaraciones.
struct nodoDeclaracion* agregarDeclaracion (struct nodoDeclaracion* puntero, char* nuevoId, char* nuevoTipo, int nuevaLinea) {

	// Crea un nuevo nodo de declaración.
	struct nodoDeclaracion* nuevo;

	nuevo = (struct nodoDeclaracion*) malloc(sizeof(struct nodoDeclaracion));

	char* nuevoID, *nuevoTIPO;

	nuevoID = (char*) malloc(sizeof(char*));
	nuevoTIPO = (char* ) malloc(sizeof(char*));

	strcpy(nuevoID,nuevoId);
	strcpy(nuevoTIPO,nuevoTipo);

	nuevo->id = nuevoID;
	nuevo->tipo = nuevoTIPO;
	nuevo->linea = nuevaLinea;
	nuevo->next = NULL;

	// Agrega el nuevo nodo a la lista de declaraciones.
	if(puntero != NULL) {

        struct nodoDeclaracion* aux = puntero;

        while(aux->next != NULL){

            aux = aux->next;

        }

        aux->next = nuevo;

    } else {

        puntero = nuevo;

    }

    return puntero;
}

// Función para agregar una función a la lista de funciones.
struct nodoFuncion* agregarFuncion (struct nodoFuncion* puntero, char* nuevoId,char* nuevoTipo, int nuevaLinea) {
	// Crea un nuevo nodo de función.
	struct nodoFuncion* nuevo;

	nuevo = (struct nodoFuncion*)malloc(sizeof(struct nodoFuncion));

	char* nuevoID,*nuevoTIPO;

	nuevoID = (char*)malloc(sizeof(char*));
	nuevoTIPO = (char*)malloc(sizeof(char*));

	strcpy(nuevoID,nuevoId);
	strcpy(nuevoTIPO,nuevoTipo);

	nuevo->id = nuevoID;
	nuevo->tipo = nuevoTIPO;
	nuevo->linea = nuevaLinea;
	nuevo->next = NULL;

	// Agrega el nuevo nodo a la lista de funciones.
	if(puntero != NULL) {

        struct nodoFuncion* aux = puntero;

        while(aux->next != NULL) {

            aux = aux->next;

        }

        aux->next = nuevo;

    } else {

        puntero = nuevo;

    }

    return puntero;
}

// Función para agregar una sentencia a la lista de sentencias.
struct nodoSentencia* agregarSentencia (struct nodoSentencia* puntero, char* nuevoTipo, int nuevaLinea) {

	// Crea un nuevo nodo de sentencia.
	struct nodoSentencia* nuevo;

	nuevo = (struct nodoSentencia*) malloc(sizeof(struct nodoSentencia));

	char* nuevoTIPO;

	nuevoTIPO = (char* ) malloc(sizeof(char*));

	strcpy(nuevoTIPO,nuevoTipo);

	nuevo->tipo = nuevoTIPO;
	nuevo->linea = nuevaLinea;
	nuevo->next = NULL;

	// Agrega el nuevo nodo a la lista de sentencias.
	if(puntero != NULL) {

        struct nodoSentencia* aux = puntero;

        while(aux->next != NULL) {

            aux = aux->next;

        }

        aux->next = nuevo;

    } else {

        puntero = nuevo;

    }

    return puntero;
}

// Función para mostrar la lista de declaraciones.
void mostrarListaDeclaraciones (struct nodoDeclaracion* puntero) {

    struct nodoDeclaracion* aux = puntero;

	printf("\n\n-----------------------------------------------------------------------------\n");
	printf("Declaraciones: \n");
	printf("-----------------------------------------------------------------------------\n");

    if(puntero!=NULL) {

		printf("TIPO\t\tIDENTIFICADOR\t\tLINEA\n\n");

        while(aux!=NULL) {

			printf("%s\t\t%s\t\t\t%d\n", aux->tipo, aux->id, aux->linea);

            aux=aux->next;
        }
	}
}

// Función para mostrar la lista de funciones.
void mostrarListaFuncion(struct nodoFuncion* puntero) {
    struct nodoFuncion* aux = puntero;

	printf("\n\n-----------------------------------------------------------------------------\n");
	printf("Funciones: \n");
	printf("-----------------------------------------------------------------------------\n");

    if(puntero != NULL){

		printf("TIPO\t\tIDENTIFICADOR\t\tLINEA\n\n");

        while(aux != NULL) {

            printf("%s\t\t%s\t\t\t%d\n",aux->tipo,aux->id, aux->linea);

            aux = aux->next;
        }
    }
}

// Función para mostrar la lista de sentencias.
void mostrarListaSentencias(struct nodoSentencia* puntero) {
    struct nodoSentencia* aux = puntero;

	printf("\n\n-----------------------------------------------------------------------------\n");
	printf("Sentencias: \n");
	printf("-----------------------------------------------------------------------------\n");

    if(puntero != NULL){

		printf("TIPO\t\tLINEA\n\n");

        while(aux != NULL) {

            printf("%s\t\t%d\n",aux->tipo, aux->linea);

            aux = aux->next;
        }
    }
}

#endif// FUNCIONES_H