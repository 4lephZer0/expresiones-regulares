#include <stdio.h>

/*
Entradas: cadena: cadena de caracteres de la expresion.
          opciones: lista de opciones que muestran las expresiones que son o no son regulares y el total de lineas.
          fichero: es el fichero de salida.

Salidas: al ser void no retorna nada, pero calcula las expresiones regulares.

Descripción:calcRegular es una funcion que se encarga de calcular si la cadena
            de caracateres es una expresion regular o no.

            la lista de opciones tiene como variables:

            opciones[0] = Las expresiones que si son regulares.
            opciones[1] = Las expresiones que no son regulares.
            opciones[2] = El total de lineas que fueron leidas.
*/
void detector(char* const entrada, char* const salida, int console);

/*
Entrada: fichero: fichero de lectura.
         fichero2: fichero de salida.
         console: valor que se encarga de imprimir en consola segun la flag -b

Salida: al ser una funcion void no retorna nada.

Descripcion: calcular es una funcion que se encarga tanto, de llamar a calcRegular, como de
escribir las ultimas 3 lineas del archivo (las expresiones que son o no son regulares y el total)
*/
void calcRegular(char* const cadena, int* opciones, FILE* fichero2);

/*
Entrada: entrada: nombre del archivo de lectura.
         salida: nombre del archivo de salida.
         console: valor que se encarga de imprimir en consola segun la flag -b

Salida: al ser una funcion void no retorna nada.

Descripcion: detector es una funcion que se encarga tanto, de llamar a calcular, como de
             abrir los archivos de entrada y salida; y tambien de cerrar dichos archivos.
*/
void calcular(FILE* fichero, FILE* fichero2, int console);