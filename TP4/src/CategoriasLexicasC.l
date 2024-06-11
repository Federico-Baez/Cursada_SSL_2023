%option noyywrap
%option yylineno

%{
 

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>





/* Es indispensable que incluyamos el archivo de cabecera con las definiciones de YACC (*.tab.h) que se genera a partir del archivo fuente de YACC (*.y) */
#include "../obj/EstructurasDeFraseC.tab.h"


char mensajeError[100];
struct nodoErrores* ListaDeErroresLexicos = NULL;

%}

%option noyywrap
CONST_DECIMAL 	      [1-9][0-9]*
CONST_OCTAL		      0[0-7]*
CONST_HEXADECIMAL	  0[xX][A-Fa-f0-9]+
CONST_REAL	          [0-9]*\.[0-9]+([eE]([\+\-]?)[0-9]+)?|[0-9]+\.([eE]([\+\-]?)[0-9]+)?|[0-9]+[eE]([\+\-]?)[0-9]+
CONST_CHAR	          "'"."'"
LITERAL_CADENA        \"([ -!#-~]|\\\")*\"
PRESERVADA	          auto|register|extern|const|default|goto
TIPOS_DE_DATOS        char\*|char|float|long|double|short|int
MODALIDAD             const|signed|static|unsigned|volatile
IDENTIFICADOR         [a-zA-Z_][a-zA-Z0-9_]*
COMENTARIO            \/\/(.)*|\/\*(.|\n)*\*\/

%%

return {
    strcpy(yylval.textoPlano,yytext);   
    return RETURN;
}

while {
	yylloc.last_column += yyleng;
    strcpy(yylval.textoPlano,yytext); 
    return WHILE;
}

void {
    strcpy(yylval.textoPlano,yytext);  
    return VOID;
}

do {
    strcpy(yylval.textoPlano,yytext);   
    return DO;
}

continue {
    strcpy(yylval.textoPlano,yytext);   
    return CONTINUE;
}

break {
    strcpy(yylval.textoPlano,yytext);  
    return BREAK;
}

if {
    strcpy(yylval.textoPlano,yytext);  
    return IF;
}

else {
    strcpy(yylval.textoPlano,yytext);   
    return ELSE;
}

for {
    strcpy(yylval.textoPlano,yytext);
    return FOR;
}

typedef {
    strcpy(yylval.textoPlano,yytext);   
    return TYPEDEF;
}

switch {
    strcpy(yylval.textoPlano,yytext);   
    return SWITCH;
}

case {
    strcpy(yylval.textoPlano,yytext);   
    return CASE;
}

sizeof {
    strcpy(yylval.textoPlano,yytext);
    return SIZEOF;
}

{TIPOS_DE_DATOS} {
    strcpy(yylval.textoPlano,yytext);
    strcpy(yylval.tipo,yytext); 
    return TIPOS_DE_DATOS;
}

{PRESERVADA} {
    strcpy(yylval.textoPlano,yytext);  
    return PRESERVADA;
}

{MODALIDAD} {
    strcpy(yylval.textoPlano,yytext); 
    return MODALIDAD;
}

{IDENTIFICADOR} {
    strcpy(yylval.textoPlano,yytext); 
    return IDENTIFICADOR;
}

{CONST_DECIMAL} {
    strcpy(yylval.tipo,"int");
    yylval.dato1 = atoi(yytext);
    return CONSTANTES;
}

{CONST_OCTAL} {
    strcpy(yylval.tipo,"int");
    yylval.dato1 = atoi(yytext);
    return CONSTANTES;
}

{CONST_HEXADECIMAL} {
    strcpy(yylval.tipo,"int");
    yylval.dato1 = atoi(yytext);
    return CONSTANTES;
}

{CONST_REAL} {
    strcpy(yylval.tipo,"float");
    yylval.dato2 = atoi(yytext);
    return CONSTANTES;
}

{CONST_CHAR} {
    strcpy(yylval.tipo,"char");
    yylval.dato3 = atoi(yytext);
    return CONSTANTES;
}

{LITERAL_CADENA} {
    strcpy(yylval.tipo,"char*");
    return LITERAL_CADENA;
}

"++" {
    return INCREMENTO;
}

"--" {
    return DECREMENTO;
}

"&&" {
    return AND;
}

"||" {
    return OR;
}

"+=" {
    return SUMADIRECTA;
}

"-=" {
    return RESTADIRECTA;
}

">=" {
    return MAYORIGUAL;
}

"=<" {
    return MENORIGUAL;
}

"!=" {
    return DESIGUALDAD;
}

"==" {
    return IGUALDAD;
}

"->" {
    return PERTENECE;
}

"=" {
    return '=';
}
   
"." {
    return '.';
}
      
"!" {
    return '!';
}
   
"<" {
    return '<';
}
   
">" {
    return '>';
}
   
"+" {
    return '+';
}
   
"-" {
    return '-';
}
   
"*" {
    return '*';
}
   
"/" {
    return '/';
}
   
"%" {
    return '%';
}
   
"&" {
    return '&';
}
   
"(" {
    return '(';
}
   
")" {
    return ')';
}
   
"{" {
    return '{';
}

";" {
    return ';';
}

"," {
    return ',';
}
   
"}" {
    return '}';
}

{COMENTARIO} 

"\n" {
    return '\n';
}
   
"\t"

[ ]

. {
    /* printf("%s no reconocido en la linea %d \n", yytext, yylineno); */
    sprintf(mensajeError, "Caracter '%s' no reconocido en la linea: %d", yytext, yylineno);
    ListaDeErroresLexicos = agregarError(ListaDeErroresLexicos, mensajeError);
}
         
%%