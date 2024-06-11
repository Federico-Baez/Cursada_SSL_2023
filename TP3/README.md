Trabajo Práctico n° 3 - BISON para reconocimiento de estructuras de frase

Implementar en C un programa que permita reconocer expresiones, declaraciones de variables, declaraciones de funciones, sentencias de distintos tipos y definiciones de funciones. El mismo deberá tomar un archivo de texto como entrada (archivo fuente .c) y dar como salida en pantalla un reporte de las variables declaradas indicando tipo de dato correspondiente, funciones declaradas, tipos sentencias encontradas indicando en todos los casos el número de línea que corresponda. Deberá indicarse aquellas secuencias de caracteres que no pertenezcan a ninguna categoría léxica o bien estructuras que no sean válidas sintácticamente. Para desarrollar dicho programa deberá utilizar LEX/FLEX combinado con YACC/BISON para la generación del código C.

Las gramáticas pueden ser extraídas del volumen 1 del apunte de la cátedra, en varios casos pueden empezar implementando las producciones más sencillas y luego ir agregando complejidad.

Observaciones:
Considerar únicamente declaraciones de variables simples. En caso de mayor complejidad considerar tipos de dato puntero, arreglo, puntero de puntero, structs, unions.
Ir de menos a más en la construcción de las gramáticas. Camino sugerido: expresiones, declaraciones, sentencias. Hacerlo de forma iterativa e ir probando.
En ningún caso copiar y pegar la gramática en un solo paso.

La entrega de este trabajo práctico es obligatoria, su fecha límite para consulta, entrega y revisión es el día Domingo 22 de Octubre. Luego de esa fecha, no se aceptarán más trabajos, y toda consulta referida quedará para la defensa final que será en el mes de noviembre.

El entorno de programación queda a criterio de cada grupo de trabajo (Eclipse, Dev, Codeblocks, Visual Studio Code ). Se recomienda un IDE que esté integrado con Git para poder realizar el trabajo en equipo de una forma más práctica.

Formará parte de la entrega, como mínimo, el archivo fuente (.c) y el archivo ejecutable (.exe). Todo debe estar en el repositorio GitHub.

La entrega será a través del repositorio de GitHub en la carpeta correspondiente a cada TP mediante pull request (PR) desde la branch creada para el TP3 hacia la rama principal.

Las consultas podrán ser respondidas a través Discord. Es importante que los utilices para compartir sus dudas con el resto de los compañeros.

Muchos éxitos 😊
