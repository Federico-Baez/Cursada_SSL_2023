%option noyywrap
%option yylineno

%{
#include <stdio.h>
#include "funciones.h"


node_t *ListaComentariosSimples = NULL;
node_t *ListaComentariosMultiples = NULL;
node_t *ListaNoReconocido = NULL;
node_t *ListaIdentificadores = NULL;
node_t *ListaCadenas = NULL;
node_t *ListaPalabrasReservadas = NULL;
node_t *ListaOctales = NULL;
node_t *ListaHexadecimales = NULL;
node_t *ListaDecimales = NULL;
node_t *ListaConstantesReales = NULL; 
node_t *ListaConstantesCaracter = NULL;
node_t *ListaCaracteresPuntuacionOperadores = NULL;
%}

DIGITO_DECIMAL [0-9]
DIGITO_OCTAL [0-7]
DIGITO_HEXADECIMAL [0-9a-fA-F]
REALES ([0-9]*\.[0-9]+|[0-9]+\.[0-9]*)(f|([Ee](\+|\-)?[0-9]+))?
LETRA [a-zA-Z]
CARACTERES_PUNTUACION_OPERADORES [\(\)\[\]\{\}\-*,:=#;.~!&+/%<>|^?]|\.{3}|\-\>|\+\+|\-\-|\<\<|\>\>|\<\=|\>\=|\=\=|\!\=|\*\=|\/\=|\%\=|\+\=|\-\=|\<\<\=|\>\>\=|\&\=|\^\=|\#\#|\|\=|\|\||\&\&|sizeof
TIPOS_DE_DATO (void|float|double|char|int)(\*)?|(short|long)(\*)?|enum|struct|union|typedef|signed|unsigned
ESTRUCTURAS_DE_CONTROL if|else|switch|case|break|continue|default|for|while|do|return|goto
IDENTIFICADORES ({LETRA}|_)({LETRA}|{DIGITO_DECIMAL}|_)*
OTRAS_PALABRAS_RESERVADAS auto|const|extern|register|static|volatile

%%

[1-9]{DIGITO_DECIMAL}* {
	agregarALista(&ListaDecimales, yytext);
	}
0{DIGITO_OCTAL}* {
	char value[10];
	long numero = strtol(yytext, NULL, 8);
	sprintf(value, "%li", numero);
	agregarALista(&ListaOctales, value); 
	}
0[xX]{DIGITO_HEXADECIMAL}+ {
	char value[10];
	long numero = strtol(yytext, NULL, 16);
	sprintf(value,"%li", numero);
	agregarALista(&ListaHexadecimales, value);
	}
{REALES} {
	agregarALista(&ListaConstantesReales, yytext);
	}
'(\\[nabefprtuvx']|[^'\\])' {
	agregarALista(&ListaConstantesCaracter, yytext);
	}
 
\"(\\.|[^"\\])*\" {insertarPorLongitud(&ListaCadenas, yytext, yyleng);}

{CARACTERES_PUNTUACION_OPERADORES} {
    insertaOrdenado(&ListaCaracteresPuntuacionOperadores, yytext);
}

{TIPOS_DE_DATO} {agregarALista(&ListaPalabrasReservadas, yytext); }
{ESTRUCTURAS_DE_CONTROL} {agregarALista(&ListaPalabrasReservadas, yytext);}
{OTRAS_PALABRAS_RESERVADAS} {agregarALista(&ListaPalabrasReservadas, yytext);}

{IDENTIFICADORES} {insertaOrdenado(&ListaIdentificadores, yytext);}

\/\/[^\n]* {agregarALista(&ListaComentariosSimples, yytext);}
\/\*([^*]|(\*+([^*\/])))*\*+\/  {agregarALista(&ListaComentariosMultiples, yytext);}


[ ] ;

\\n ;

\\t ;

. {
    char mensaje[40];
    snprintf(mensaje, sizeof(mensaje), "%s no reconocido en la linea %d \n", yytext, yylineno);
    agregarALista(&ListaNoReconocido, mensaje);
}

%%

 
//argc: argument count  | argv: argument vector 
int main(int argc, char *argv[]) {
	// se revisa si el archivo abierto esta vacio
	// si lo esta, imprime mensaje de error por consola y retorna 1
	yyin = fopen(argv[1], "rt");
	if(yyin == NULL){
		printf("\nNo se pudo abrir el archivo: %s \n",argv[1]);
		return 1; 
	}
	// si no lo esta, lo analiza lexicamente
	else{
		printf("\nEl archivo se abrio correctamente: %s \n",argv[1]);
		/* Invocación del analizador léxico */
		yylex();
	}
	printf("\nFlex finalizo la lectura del archivo: %s \n",argv[1]);
	fclose(yyin);

	//-Reportes
	
	//-- Reporte Comentarios
	reporteComentarios(ListaComentariosSimples, ListaComentariosMultiples);

	//-- Reporte identificadores
	reporteIdentificadores(ListaIdentificadores);

	//-- Reporte Cadenas
	reporteCadenas(ListaCadenas);

	//-- Reporte Palabras Reservadas
	reportePalabrasReservadas(ListaPalabrasReservadas);

	//-- Reporte Constantes
	reporteConstantes(ListaOctales, ListaHexadecimales, ListaDecimales, ListaConstantesReales, ListaConstantesCaracter);

	//-- Reporte Caracteres Puntuacion y Operadores
	reporteCaracteresPuntuacionOperadores(ListaCaracteresPuntuacionOperadores);

	//-- Reporte Caracteres No Reconocidos
    reporteCaracteresNoReconocidos(ListaNoReconocido);

    return 0;
}
