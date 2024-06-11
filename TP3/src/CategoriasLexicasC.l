%option noyywrap
%option yylineno

%{


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>



/* Es indispensable que incluyamos el archivo de cabecera con las definiciones de YACC (*.tab.h) que se genera a partir del archivo fuente de YACC (*.y) */
#include "../obj/EstructurasDeFraseC.tab.h"

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
    strcpy(yylval.string,yytext);   
    return RETURN;
}

while {
	yylloc.last_column += yyleng;
    strcpy(yylval.string,yytext); 
    return WHILE;
}

void {
    strcpy(yylval.string,yytext);  
    return VOID;
}

do {
    strcpy(yylval.string,yytext);   
    return DO;
}

continue {
    strcpy(yylval.string,yytext);   
    return CONTINUE;
}

break {
    strcpy(yylval.string,yytext);  
    return BREAK;
}

if {
    strcpy(yylval.string,yytext);  
    return IF;
}

else {
    strcpy(yylval.string,yytext);   
    return ELSE;
}

for {
    strcpy(yylval.string,yytext);
    return FOR;
}

typedef {
    strcpy(yylval.string,yytext);   
    return TYPEDEF;
}

switch {
    strcpy(yylval.string,yytext);   
    return SWITCH;
}

case {
    strcpy(yylval.string,yytext);   
    return CASE;
}

sizeof {
    strcpy(yylval.string,yytext);
    return SIZEOF;
}

{TIPOS_DE_DATOS} {
    strcpy(yylval.string,yytext);  
    return TIPOS_DE_DATOS;
}

{PRESERVADA} {
    strcpy(yylval.string,yytext);  
    return PRESERVADA;
}

{MODALIDAD} {
    strcpy(yylval.string,yytext); 
    return MODALIDAD;
}

{IDENTIFICADOR} {
    strcpy(yylval.string,yytext); 
    return IDENTIFICADOR;
}

{CONST_DECIMAL} {
    strcpy(yylval.tipo,"int");
    return CONSTANTES;
}

{CONST_OCTAL} {
    strcpy(yylval.tipo,"int");
    return CONSTANTES;
}

{CONST_HEXADECIMAL} {
    strcpy(yylval.tipo,"int");
    return CONSTANTES;
}

{CONST_REAL} {
    strcpy(yylval.tipo,"float");
    return CONSTANTES;
}

{CONST_CHAR} {
    strcpy(yylval.tipo,"char");
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
    printf("%s no reconocido en la linea %d \n", yytext, yylineno);
}
         
%%