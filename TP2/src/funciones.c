#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void agregarALista(node_t ** head, char *val) {
    node_t * new_node = (node_t *) malloc(sizeof(node_t));
    new_node->val = strdup(val);
    new_node->next = NULL;
    if(*head == NULL){
        *head = new_node;
    }
    else {
        node_t *current = *head;
        while (current->next != NULL) {
            current = current->next; // Traverse to the last node
        }
        current->next = new_node; // Append the new node to the end
    }
}


void eliminarPrimero(node_t ** head,char ** val) {
	if (*head == NULL) {
        *val = NULL;
        return;
    }
    
    node_t * ptr = *head;
	*val = strdup(ptr->val);
	*head = (*head)->next;
    free(ptr->val);
	free (ptr);
}


void insertaOrdenado(node_t **head, const char *val) {

    // Crea un nuevo nodo
    node_t *newNode = (node_t *)malloc(sizeof(node_t));
    newNode->val = strdup(val);
    newNode->next = NULL;

    // Si la lista está vacía o el nuevo nodo debe ir al principio
    if (*head == NULL || strcmp(newNode->val, (*head)->val) < 0) {
        newNode->next = *head;
        *head = newNode;
    } else {
        // Encuentra la posición adecuada para insertar el nuevo nodo
        node_t *current = *head;
        while (current->next != NULL && strcmp(newNode->val, current->next->val) >= 0) {
            current = current->next;
        }
        // Inserta el nuevo nodo en la posición correcta
        newNode->next = current->next;
        current->next = newNode;
    }
}

void insertarPorLongitud(node_t **head, const char *val, int length) {
    // Comprueba si el nuevo literal cadena ya está en la lista
    node_t *current = *head;
    while (current != NULL) {
        if (strcmp(current->val, val) == 0) {
            return;  // Ya existe, no lo agregamos
        }
        current = current->next;
    }

    // Crea un nuevo nodo
    node_t *newNode = (node_t *)malloc(sizeof(node_t));
    newNode->val = strdup(val);
    newNode->next = NULL;

    // Si la lista está vacía o el nuevo nodo debe ir al principio
    if (*head == NULL || length < strlen((*head)->val)) {
        newNode->next = *head;
        *head = newNode;
    } else {
        // Encuentra la posición adecuada para insertar el nuevo nodo
        current = *head;
        while (current->next != NULL && length >= strlen(current->next->val)) {
            current = current->next;
        }
        // Inserta el nuevo nodo en la posición correcta
        newNode->next = current->next;
        current->next = newNode;
    }
}

//-Reportes
//--Reporte Comentarios
void reporteComentarios(node_t *ListaComentariosSimples, node_t *ListaComentariosMultiples){
    char * valor;
    int contador = 1;
        printf("\n\n-----------------------------------------------------------------------------\n");
        printf("Reporte Comentarios: \n");
        printf("-----------------------------------------------------------------------------\n");
        printf("Comentarios Simples: \n");
        while(ListaComentariosSimples != NULL){
            eliminarPrimero(&ListaComentariosSimples, &valor);
            printf("%d. \n%s \n", contador, valor);
            contador++;
        }
        contador = 1;
        printf("----------------------------------------------------------------------------- \n");
        printf("Comentarios Multiples: \n");
        while(ListaComentariosMultiples != NULL){
            eliminarPrimero(&ListaComentariosMultiples, &valor);
            printf("%d. \n%s \n", contador, valor);
            contador++;
        }
        printf("----------------------------------------------------------------------------- \n");
}

//--Reporte Identificadores
void reporteIdentificadores(node_t *ListaIdentificadores){
    char * valor;
    int contador = 1;
        printf("\n\n-----------------------------------------------------------------------------\n");
        printf("Reporte Identificadores: \n");
        printf("-----------------------------------------------------------------------------\n");
        while(ListaIdentificadores != NULL){
            eliminarPrimero(&ListaIdentificadores, &valor);
            printf("%d. %s \n", contador, valor);
            contador++;
        }
        printf("-----------------------------------------------------------------------------\n");
}

//--Reporte Literales Cadenas
void reporteCadenas(node_t *ListaCadenas){
    char * valor;
    int contador = 1;
    int longitudCadena;
        printf("\n\n-----------------------------------------------------------------------------\n");
        printf("Reporte Cadenas: \n");
        printf("-----------------------------------------------------------------------------\n");
        while(ListaCadenas != NULL){
            eliminarPrimero(&ListaCadenas, &valor);
            longitudCadena = strlen(valor) - 2;
            printf("%d. %s longitud: %d \n", contador, valor, longitudCadena);
            contador++;
        }
        printf("-----------------------------------------------------------------------------\n");
}

//--Reporte Palabras Reservadas
void reportePalabrasReservadas(node_t *ListaPalabrasReservadas){
    char * valor;
    int contador = 1;
        printf("\n\n-----------------------------------------------------------------------------\n");
        printf("Reporte Palabras Reservadas: \n");
        printf("-----------------------------------------------------------------------------\n");
        while(ListaPalabrasReservadas != NULL){
            eliminarPrimero(&ListaPalabrasReservadas, &valor);
            printf("%d. %s \n", contador, valor);
            contador++;
        }
        printf("-----------------------------------------------------------------------------\n");
}
 
//--Reporte Constantes
void reporteConstantes(node_t *ListaOctales, node_t *ListaHexadecimales, node_t *ListaDecimales, node_t *ListaConstantesReales, node_t *ListaConstantesCaracter){
    char * valor;
    int contador = 1;
        printf("\n\n-----------------------------------------------------------------------------\n");
        printf("Reporte Constantes: \n");
        printf("-----------------------------------------------------------------------------\n");
        printf("Lista Octales: \n");
        while(ListaOctales != NULL){
            eliminarPrimero(&ListaOctales, &valor);
            printf("%d. %s \n", contador, valor);
            contador++;
        }
        contador = 1;
        printf("-----------------------------------------------------------------------------\n");
        printf("Lista Hexadecimales: \n");
        while(ListaHexadecimales != NULL){
            eliminarPrimero(&ListaHexadecimales, &valor);
            printf("%d. %s \n", contador, valor);
            contador++;
        }
        contador = 1;
        printf("-----------------------------------------------------------------------------\n");
        printf("Lista Decimales: \n");
        long suma = 0;
        while(ListaDecimales != NULL){
            eliminarPrimero(&ListaDecimales, &valor);
            printf("%d. %s \n", contador, valor);
            suma += atoi(valor);
            contador++;
        }
        contador = 1;
        printf("total sumado de decimales = %li \n", suma );
        printf("-----------------------------------------------------------------------------\n");
        printf("Lista Constantes Reales: \n");
        while(ListaConstantesReales != NULL){
            eliminarPrimero(&ListaConstantesReales, &valor);
            int parteEntera = atof(valor); 
            double mantisa = atof(valor) - parteEntera;
            printf("%d. Parte Entera = %d , Mantisa = %f \n", contador, parteEntera, mantisa);
            contador++;
        }
        contador = 1;
        printf("-----------------------------------------------------------------------------\n");
        printf("Lista Constantes Caracter: \n");
        while(ListaConstantesCaracter != NULL){
            eliminarPrimero(&ListaConstantesCaracter, &valor);
            printf("%d. %s \n", contador, valor);
            contador++;
        }
        printf("-----------------------------------------------------------------------------\n");
}

//-- Reporte Caracteres Puntuacion y Operadores
void reporteCaracteresPuntuacionOperadores(node_t *ListaCaracteresPuntuacionOperadores) {
    int contador = 1;
    printf("\n\n-----------------------------------------------------------------------------\n");
    printf("Reporte Caracteres Puntuacion y Operadores: \n");
    printf("-----------------------------------------------------------------------------\n");
    node_t *current = ListaCaracteresPuntuacionOperadores;
    while (current != NULL) {
        int contadorOcurrenciasOperadores = 1;
        while (current->next != NULL && strcmp(current->val, current->next->val) == 0) {
            current = current->next;
            contadorOcurrenciasOperadores++;
        }
        printf("%d. %s tiene: %d ocurrencias\n", contador, current->val, contadorOcurrenciasOperadores);
        current = current->next;
        contador++;
    }
}

//-- Reporte Caracteres No Reconocidos
void reporteCaracteresNoReconocidos(node_t *ListaNoReconocido) {
    int contador = 1;
    printf("\n\n-----------------------------------------------------------------------------\n");
    printf("Reporte Caracteres No Reconocidos: \n");
    printf("-----------------------------------------------------------------------------\n");
    node_t *current = ListaNoReconocido;
    while (current != NULL) {
        char *mensaje = current->val;
        int linea;
        printf("%d. %s \n", contador, mensaje);
        current = current->next;
        contador ++;
    }
}