%{

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funciones.h"

/* Declaraciones de variables globales */
int flag_error=0;
extern FILE *yyout;
extern FILE *yyin;
extern int yylineno;

int lineaSentencia;
int lineaError;

/* Declaraciones de estructuras de datos globales */ 
struct nodoDeclaracion* ListaDeclaraciones = NULL;
struct nodoFuncion* ListaFunciones = NULL;
struct nodoSentencia* ListaSentencias = NULL;

%}

// %error-verbose
//  Para activar el seguimiento de las ubicaciones de los tokens (número de linea, número de columna)
%locations

%union
{
  char string[50];
  char tipo[10];
}

/*%union
{
  int tipo;
  char textoPlano[50];
  int dato;
  double dato2;
  char dato3;
}*/

// Definición de tokens
%token<string> CONSTANTES LITERAL_CADENA IDENTIFICADOR
%token<string> TIPOS_DE_DATOS PRESERVADA MODALIDAD AND PUNTUACION INCREMENTO DECREMENTO SUMADIRECTA RESTADIRECTA OR VOID MAYORIGUAL MENORIGUAL PERTENECE DESIGUALDAD IGUALDAD RETURN IF DO WHILE ELSE FOR TYPEDEF SIZEOF SWITCH CASE BREAK CONTINUE CONTROLOTRA OPERADOR CONDICION DEFAULT

%type <string> expresionPrimaria

// Definición de tokens
%left '*' '/'
%left '+' '-'  AND OR
%left IGUALDAD DESIGUALDAD
%left ','
%right INCREMENTO DECREMENTO SIZEOF '&' '!'
%right ':' '?'  
%right RESTADIRECTA SUMADIRECTA '=' 
%nonassoc '{' '}' '[' ']' '(' ')'

// Dónde empieza la BNF (punto de partida para el análisis sintáctico de un programa) 
%start input

%% /* A continuacion las reglas gramaticales y las acciones */

/*  ------------------------------------ REGLAS GRAMATICALES DE C ------------------------------------ */

input
  : 
  | input line 
  ;
  
line
  : '\n'
  | sentencia 
  | sentencia '\n'
  | error             { printf("\nError sintactico en la linea: %d \n", yylineno-1); } 
  | error ';'         { printf("\nError sintactico en la linea: %d \n", yylineno-1); } 
  ;

/* ------------------------------------- EXPRESIONES ----------------------------------------------------- */

expresion
  : expresionAsignacion 
  ;

expresionAsignacion
  : expresionCondicional 
  | expresionUnaria operacionAsignacion expresionAsignacion
  ;

operacionAsignacion
  : '='
  | SUMADIRECTA
  | RESTADIRECTA
  ;

expresionCondicional
  : expresionOr
  | expresionOr '?' expresion ':' expresion 
  ;

expresionOr
  : expresionAnd 
  | expresionOr OR expresionAnd
  ;

expresionAnd
  : expresionIgualdad 
  | expresionAnd AND expresionIgualdad
  ;

expresionIgualdad
  : expresionRelacional
  | expresionIgualdad operadorComparacion expresionRelacional
  ;

operadorComparacion
  : IGUALDAD DESIGUALDAD
  ;

expresionRelacional
  : expresionAditiva 
  | expresionRelacional operadorRelacional expresionAditiva
  ;
        
operadorRelacional
  : '>' 
  | '<' 
  | MENORIGUAL 
  | MAYORIGUAL
  ;

expresionAditiva
  : expresionMultiplicativa  
  | expresionAditiva '+' expresionMultiplicativa
  | expresionAditiva '-' expresionMultiplicativa
  ;
        
expresionMultiplicativa
  :  expresionUnaria 
  | expresionMultiplicativa '*' expresionUnaria 
  | expresionMultiplicativa '/' expresionUnaria
  ;
        
expresionUnaria
  : expresionPostfijo 
  | expresionUnaria INCREMENTO 
  | expresionUnaria DECREMENTO                 
  | operadorUnario expresionUnaria 
  | '-' expresionUnaria %prec NEG 
  | '+' expresionUnaria %prec POS 
  | '*' expresionUnaria %prec PUNT 
  ;
        
operadorUnario
  : '&'
  |'!'
  ;

expresionPostfijo
  : expresionPrimaria                 
  | expresionPostfijo'['expresion']'   
  | expresionPostfijo'('listaDeArgumentos')'
  ;
        
listaDeArgumentos
  : argumento
  | listaDeArgumentos ',' argumento
  ;
        
argumento
  : expresion
  ;

expresionPrimaria
  : CONSTANTES       
  | IDENTIFICADOR        
  | LITERAL_CADENA   
  ;

/* ------------------------------------- DECLARACIONES ----------------------------------------------------- */

declaracion
  : declaracionVariable ';'      { }
  | declaracionAsignacion ';'     { }
  | declaracionFuncion ';'        { strcpy($<tipo>$, $<tipo>1); 
                                    strcpy($<string>$, $<string>1); }
  ;

declaracionFuncion
  : TIPOS_DE_DATOS IDENTIFICADOR '('listaDeParametros')'    { ListaFunciones = agregarFuncion(ListaFunciones, $<string>2, $<string>1, yylineno); }                             
  | VOID IDENTIFICADOR '('listaDeParametros')'              { ListaFunciones = agregarFuncion(ListaFunciones, $<string>2, $<string>1, yylineno); }                                                               
  ;
  
definicionFuncion
  : TIPOS_DE_DATOS IDENTIFICADOR '('listaDeParametros')' sentenciaCompuesta   { ListaFunciones = agregarFuncion(ListaFunciones, $<string>2, $<string>1, yylineno); }
  | VOID IDENTIFICADOR '('listaDeParametros')' sentenciaCompuesta             { ListaFunciones = agregarFuncion(ListaFunciones, $<string>2, $<string>1, yylineno); }           
  ;

listaDeParametros
  : 
  | parametro 
  | listaDeParametros ',' parametro 
  ;
  
parametro
  : TIPOS_DE_DATOS IDENTIFICADOR  
  ;

declaracionVariable
  : TIPOS_DE_DATOS listaDeVariables { ListaDeclaraciones = agregarDeclaracion(ListaDeclaraciones, $<string>1, $<string>2, yylineno); }
  ;

declaracionAsignacion
  :TIPOS_DE_DATOS listaDeVariablesAsignacion { ListaDeclaraciones = agregarDeclaracion(ListaDeclaraciones, $<string>1, $<string>2, yylineno); }
  ;


listaDeVariables
  : variable  
  | variable ',' listaDeVariables 
  ;

listaDeVariablesAsignacion
  : variableAsignacion  
  | variableAsignacion ',' listaDeVariablesAsignacion 
  ;
  
variable
  : IDENTIFICADOR    
  ;

variableAsignacion
  : IDENTIFICADOR '=' expresionAsignacion   
  ;

/* ------------------------------------- SENTENCIAS ----------------------------------------------------- */

sentenciaCompuesta
  : '{'listaCompuesta'}'
  ;

listaCompuesta
  :  
  | line listaCompuesta 
  ;

sentencia
  : sentenciaCompuesta  { strcpy($<tipo>$, $<tipo>1); 
                          strcpy($<string>$, $<string>1); }
  | sentenciaExpresion  { strcpy($<tipo>$, $<tipo>1); 
                          strcpy($<string>$, $<string>1); }
  | sentenciaSeleccion  { strcpy($<tipo>$, $<tipo>1); 
                          strcpy($<string>$, $<string>1); }
  | sentenciaIteracion  { strcpy($<tipo>$, $<tipo>1); 
                          strcpy($<string>$,$<string>1); }
  | sentenciaSalto      { strcpy($<tipo>$, $<tipo>1); 
                          strcpy($<string>$, $<string>1); }
  | declaracion         { strcpy($<tipo>$, $<tipo>1); 
                          strcpy($<string>$, $<string>1); }
  | definicionFuncion
  ;
  
sentenciaExpresion
  : ';'       
  | expresion';'  { strcpy($<tipo>$, $<tipo>1); 
                    strcpy($<string>$, $<string>1); }
  ;

sentenciaSeleccion
  : { lineaSentencia = yylineno; } IF '('expresion ')' sentencia ELSE sentencia  { ListaSentencias = agregarSentencia(ListaSentencias, $<string>2, lineaSentencia);}
  | { lineaSentencia = yylineno; } IF '('expresion')' sentencia                  { ListaSentencias = agregarSentencia(ListaSentencias, $<string>2, lineaSentencia);}
  ;

sentenciaIteracion
  : { lineaSentencia = yylineno; } WHILE '(' expresion ')' sentencia                                               { ListaSentencias = agregarSentencia(ListaSentencias, $<string>2, lineaSentencia);}
  | { lineaSentencia = yylineno; } DO sentencia WHILE '(' expresion ')' ';'                                        { ListaSentencias = agregarSentencia(ListaSentencias, $<string>2, lineaSentencia);}
  | { lineaSentencia = yylineno; } FOR '(' expresionOP ';' expresionOP ';' expresionOP ')' sentenciaCompuesta      { ListaSentencias = agregarSentencia(ListaSentencias, $<string>2, lineaSentencia);}
  ;

sentenciaSalto
  : RETURN expresion ';' { ListaSentencias = agregarSentencia(ListaSentencias, $<string>1, yylineno); }
  ;

expresionOP
  : 
  | expresion
  ;

%%

int main(){

  yyin = fopen("./codigoTest.c", "r");
  #if YYDEBUG
          yydebug = 1;
  #endif

	if(yyin == NULL){
		printf("\nError: No se pudo abrir el archivo \n"); 
	}
  else{
		printf("\nEl archivo se abrio correctamente \n");
    printf("\nAnalisis sintactico del archivo: \n");


    printf("\n\n-----------------------------------------------------------------------------\n");
    printf("Errores lexicos y sintacticos: \n");
    printf("-----------------------------------------------------------------------------\n");

		yyparse();
	}

	fclose(yyin);

  mostrarListaDeclaraciones(ListaDeclaraciones);
  mostrarListaFuncion(ListaFunciones);
  mostrarListaSentencias(ListaSentencias);

  return 0;
}