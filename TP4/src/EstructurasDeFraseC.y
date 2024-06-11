%{

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#include "funciones.h"
#include "tablaDeSimbolos.h"

/* Declaraciones de variables globales */
int flag_error=0;
extern FILE *yyout;
extern FILE *yyin;
extern int yylineno;

char mensajeError[100];

int lineaSentencia;
int lineaError;

/* Declaraciones de estructuras de datos globales */ 

// listas tp integrador
struct nodoVariableTS* ListaVariablesTS = NULL;
struct nodoFuncionTS* ListaFuncionesTS = NULL;
struct nodoParametroTS* ListaParamtrosTS = NULL;

struct nodoParametrosInvocacionTS* AuxListaParamtrosNombresTS = NULL;

extern struct nodoErrores* ListaDeErroresLexicos;
struct nodoErrores* ListaDeErroresSintacticos = NULL;
extern struct nodoErrores* ListaDeErroresSemanticos;

struct nodoFuncion* ListaFunciones = NULL;

%}

// %error-verbose 
//  Para activar el seguimiento de las ubicaciones de los tokens (número de linea, número de columna)
%locations

%union
{
  char tipo[10];
  char textoPlano[50];

  int dato1;
  double dato2;
  char dato3;
}

// Definición de tokens
%token<textoPlano> CONSTANTES LITERAL_CADENA IDENTIFICADOR
%token<textoPlano> TIPOS_DE_DATOS PRESERVADA MODALIDAD AND PUNTUACION INCREMENTO DECREMENTO SUMADIRECTA RESTADIRECTA OR VOID MAYORIGUAL MENORIGUAL PERTENECE DESIGUALDAD IGUALDAD RETURN IF DO WHILE ELSE FOR TYPEDEF SIZEOF SWITCH CASE BREAK CONTINUE CONTROLOTRA OPERADOR CONDICION DEFAULT

%type <textoPlano> expresionPrimaria

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
  | error             {  sprintf(mensajeError, "Error sintactico en la linea: %d", yylineno-1);
                         ListaDeErroresSintacticos = agregarError(ListaDeErroresSintacticos, mensajeError); } 
  | error ';'         { sprintf(mensajeError, "Error sintactico en la linea: %d", yylineno-1);
                         ListaDeErroresSintacticos = agregarError(ListaDeErroresSintacticos, mensajeError); }  
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
  | expresionAditiva '+' expresionMultiplicativa { validacionDeTiposEnOperacionesBinarias(ListaVariablesTS, $<textoPlano>1, $<textoPlano>3, yylineno);}
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
  | expresionPostfijo'('listaDeArgumentos')' { validacionGeneralDeParametros(ListaFuncionesTS,ListaVariablesTS, $<textoPlano>1, AuxListaParamtrosNombresTS);
                                               AuxListaParamtrosNombresTS = NULL; }
  ;
        
listaDeArgumentos
  : argumento
  | listaDeArgumentos ',' argumento
  ;
        
argumento
  : expresion { AuxListaParamtrosNombresTS = agregarParametroInvocacion(AuxListaParamtrosNombresTS, $<textoPlano>1);}
  ;

expresionPrimaria
  : CONSTANTES       
  | IDENTIFICADOR   
  | LITERAL_CADENA   
  ;

/* ------------------------------------- DECLARACIONES ----------------------------------------------------- */

declaracion
  : declaracionVariable ';'     
  | declaracionAsignacion ';'    
  | declaracionFuncion ';'        { strcpy($<tipo>$, $<tipo>1); 
                                    strcpy($<textoPlano>$, $<textoPlano>1); }
  ;

declaracionFuncion 
  : TIPOS_DE_DATOS IDENTIFICADOR '('listaDeParametros')'                             { ListaFunciones = agregarFuncion(ListaFunciones, $<textoPlano>2, $<textoPlano>1, yylineno);
                                                                                      ListaFuncionesTS = validarDobleDeclaracionDeFunciones(ListaFuncionesTS, $<textoPlano>2, $<textoPlano>1, ListaParamtrosTS);
                                                                                      ListaParamtrosTS = NULL;}
  | VOID IDENTIFICADOR '('listaDeParametros')'                  { ListaFunciones = agregarFuncion(ListaFunciones, $<textoPlano>2, $<textoPlano>1, yylineno);
                                                                  ListaFuncionesTS = validarDobleDeclaracionDeFunciones(ListaFuncionesTS, $<textoPlano>2, $<textoPlano>1, ListaParamtrosTS);
                                                                  ListaParamtrosTS = NULL;
                                                                  }
  ;
  
definicionFuncion
  : TIPOS_DE_DATOS IDENTIFICADOR '('listaDeParametros')' sentenciaCompuesta   {
                                                            ListaFunciones = agregarFuncion(ListaFunciones, $<textoPlano>2, $<textoPlano>1, yylineno);
                                                            // ListaFuncionesTS = validarDobleDeclaracionDeFunciones(ListaFuncionesTS, $<textoPlano>2, $<textoPlano>1, ListaParamtrosTS); 
                                                            ListaFuncionesTS = validarDobleDeclaracionDeFunciones(ListaFuncionesTS, $<textoPlano>2, $<textoPlano>1, ListaParamtrosTS);
                                                            ListaParamtrosTS = NULL; }
  | VOID IDENTIFICADOR '('listaDeParametros')' sentenciaCompuesta         { ListaFunciones = agregarFuncion(ListaFunciones, $<textoPlano>2, $<textoPlano>1, yylineno);
                                                                            ListaFuncionesTS = validarDobleDeclaracionDeFunciones(ListaFuncionesTS, $<textoPlano>2, $<textoPlano>1, ListaParamtrosTS);
                                                                            ListaParamtrosTS = NULL;
                                                                            }
  ;

listaDeParametros
  : 
  | parametro 
  | listaDeParametros ',' parametro 
  ;
  
parametro
  : TIPOS_DE_DATOS IDENTIFICADOR  { ListaParamtrosTS = agregarParametroTS(ListaParamtrosTS, $<textoPlano>2, $<textoPlano>1); }
  ;

declaracionVariable
  : TIPOS_DE_DATOS listaDeVariables { ListaVariablesTS = validarDobleDeclaracionDeVariables(ListaVariablesTS, $<textoPlano>2, $<textoPlano>1)}
  ;

declaracionAsignacion
  : TIPOS_DE_DATOS listaDeVariablesAsignacion { ListaVariablesTS = validarDobleDeclaracionDeVariables(ListaVariablesTS, $<textoPlano>2, $<textoPlano>1)}      
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
                          strcpy($<textoPlano>$, $<textoPlano>1); }
  | sentenciaExpresion  { strcpy($<tipo>$, $<tipo>1); 
                          strcpy($<textoPlano>$, $<textoPlano>1); }
  | sentenciaSeleccion  { strcpy($<tipo>$, $<tipo>1); 
                          strcpy($<textoPlano>$, $<textoPlano>1); }
  | sentenciaIteracion  { strcpy($<tipo>$, $<tipo>1); 
                          strcpy($<textoPlano>$,$<textoPlano>1); }
  | sentenciaSalto      { strcpy($<tipo>$, $<tipo>1); 
                          strcpy($<textoPlano>$, $<textoPlano>1); }
  | declaracion         { strcpy($<tipo>$, $<tipo>1); 
                          strcpy($<textoPlano>$, $<textoPlano>1); }
  | definicionFuncion
  ;
  
sentenciaExpresion
  : ';'       
  | expresion';'  { strcpy($<tipo>$, $<tipo>1); 
                    strcpy($<textoPlano>$, $<textoPlano>1); }
  ;

sentenciaSeleccion
  : IF '('expresion ')' sentencia ELSE sentencia  
  | IF '('expresion')' sentencia                  
  ;

sentenciaIteracion
  : WHILE '(' expresion ')' sentencia                                               
  | DO sentencia WHILE '(' expresion ')' ';'                                        
  | FOR '(' expresionOP ';' expresionOP ';' expresionOP ')' sentenciaCompuesta      
  ;

sentenciaSalto
  : RETURN expresion ';'
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

		yyparse();
	}

	fclose(yyin);


  mostrarListaVariables(ListaVariablesTS);
  mostrarListaFunciones(ListaFuncionesTS);

  mostrarListaErrores(ListaDeErroresLexicos, "Lexicos");  
  mostrarListaErrores(ListaDeErroresSintacticos, "Sintacticos");
  mostrarListaErrores(ListaDeErroresSemanticos, "Semanticos");

  return 0;
}