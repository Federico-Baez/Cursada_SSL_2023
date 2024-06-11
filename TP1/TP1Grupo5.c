#include <stdio.h>
#define Q0 0
#define Q1 1
#define Q2 2
#define Q3 3
#define Q4 4
#define Q5 5
#define Q6 6

int automata (unsigned char c, int estado)
{
    int tablaEstados[7][6] = {
        //        0   [1-7] [8-9] [a-fA-F] [xX] otro
        /* q0 */ {Q1,   Q2,  Q2,  Q6,      Q6,   Q6},
        /* q1 */ {Q5,   Q5,  Q6,  Q6,      Q3,   Q6},
        /* q2 */ {Q2,   Q2,  Q2,  Q6,      Q6,   Q6},
        /* q3 */ {Q4,   Q4,  Q4,  Q4,      Q6,   Q6},
        /* q4 */ {Q4,   Q4,  Q4,  Q4,      Q6,   Q6},
        /* q5 */ {Q5,   Q5,  Q6,  Q6,      Q6,   Q6},
        /* q6 */ {Q6,   Q6,  Q6,  Q6,      Q6,   Q6},
    };

    int columna;

    if (c == '0')
    {
        columna = 0;
    }
    else if ((c >= '1') && (c <= '7')) // solo funciona porque son numeros consecutivos en la tabla ascii
    {
        columna = 1;
    }
    else if ((c == '8') || (c == '9'))
    {
        columna = 2;
    }
    else if (((c >= 'a') && (c <= 'f')) || ((c >= 'A') && (c <= 'F'))) // solo funciona porque son numeros consecutivos en la tabla ascii
    {
        columna = 3;
    }
    else if ((c == 'x') || (c == 'X'))
    {
        columna = 4;
    }
    else
    {
        columna = 5;
    }

    return tablaEstados[estado][columna];
}

int maximoEntreDosNumeros (int maximo, int contador)
{
    if (contador > maximo)
    {
        maximo = contador;
    }

    return maximo;
}

void ponerEspacios (int espaciosTotales, int contador, FILE* salida)
{
    int cantidadDeEspacios = espaciosTotales - contador;
    for (int i = 0; i < cantidadDeEspacios; i++)
    {
        putc(' ', salida);
    }
}

int calcularEspaciosTotales (int palabraMasLarga, int contador, FILE* entrada)
{
    while ( !feof(entrada) )
    {
        unsigned char c = fgetc(entrada);

        if ((c != ',') && (!feof(entrada)))
        {
            if (c == ' ')
            {
                continue;
            }
            contador++;
            palabraMasLarga = maximoEntreDosNumeros (palabraMasLarga, contador);
        }
        else
        {
            contador = 0;
        }
    }

    return palabraMasLarga;
}

int main ()
{
    FILE* entrada = fopen("entrada.txt","r");
    FILE* salida = fopen("salida.txt","w");
    int estado = Q0, contador = 0, palabraMasLarga = 0;

    int espaciosTotales = calcularEspaciosTotales(palabraMasLarga, contador, entrada) + 10;

    rewind(entrada);

    while ( !feof(entrada) )
    {
        unsigned char c = fgetc(entrada);

        if ((c != ',') && (!feof(entrada)))
        {
            if (c == ' ')
            {
                continue;
            }
            else
            {
                estado = automata(c, estado);
                putc(c, salida);
            }
            contador++;
        }
        else
        {
            switch (estado)
            {
                case Q2:
                    ponerEspacios(espaciosTotales, contador, salida);
                    fputs("DECIMAL \n",salida);
                    contador = 0;
                    break;

                case Q1: case Q5:
                    ponerEspacios(espaciosTotales, contador, salida);
                    fputs("OCTAL \n",salida);
                    contador = 0;
                    break;

                case Q4:
                    ponerEspacios(espaciosTotales, contador, salida);
                    fputs("HEXADECIMAL \n",salida);
                    contador = 0;
                    break;
                
                default:
                    if (contador == 0)
                    {
                        fputs("λ",salida);
                        ponerEspacios((espaciosTotales - 1), contador, salida);
                        fputs("NO RECONOCIDA \n",salida);
                    }
                    else
                    {
                        ponerEspacios(espaciosTotales, contador, salida);
                        fputs("NO RECONOCIDA \n",salida);
                    }
                    contador = 0;
                    break;
            }

            estado = 0;
        }
    }        

    fclose(salida);
    fclose(entrada);

    return 0; 
}