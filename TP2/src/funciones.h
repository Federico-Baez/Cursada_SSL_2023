#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructura de los punteros utilizados, su informacion es un string
typedef struct node {
    char *val;
    struct node * next;
} node_t;

// Recibe la cabeza de una lista y un string
// Agrega un elemento al final de la lista 
void agregarALista(node_t ** head, char *val);


// Recibe la cabeza de una lista y una variable string por referencia
// Elimina el primer elemento de la lista y devuelve su contenido(string) a la variable recibida por parametro
void eliminarPrimero(node_t ** head,char ** val);


// Recibe la cabeza de una lista y un string
// Agrega un elemento ordenandolo segun su valor de ASCII(ascendente) 
void insertaOrdenado(node_t **head, const char *val);

// Recibe la cabeza de una lista , un string, y la longitud de la cadena leida
// Agrega un elemento ordenandolo segun la longitud de la cadena, no agrega duplicados 
void insertarPorLongitud(node_t **head, const char *val, int length);

//-Reportes
//-- Reporte Comentarios
void reporteComentarios(node_t *ListaComentariosSimples, node_t *ListaComentariosMultiples);
//-- Reporte Identificadores
void reporteIdentificadores(node_t *ListaIdentificadores);
//-- Reporte Literales Cadena
void reporteCadenas(node_t *ListaCadenas);
//-- Reporte Palabras Reservadas
void reportePalabrasReservadas(node_t *ListaPalabrasReservadas);
//-- Reporte Constantes
void reporteConstantes(node_t *ListaOctales, node_t *ListaHexadecimales, node_t *ListaDecimales, node_t *ListaConstantesReales, node_t *ListaConstantesCaracter);
//-- Reporte Caracteres Puntuacion y Operadores
void reporteCaracteresPuntuacionOperadores(node_t *ListaCaracteresPuntuacionOperadores);
//-- Reporte Caracteres No Reconocidos
void reporteCaracteresNoReconocidos(node_t *ListaNoReconocido);
 
#endif// FUNCIONES_H