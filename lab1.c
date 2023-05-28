#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include "funciones.h"
#include <string.h>

/*
Entrada: argc y argv, argumentos para extraer los parametros de entrada del llamado al archivo.

Salida: 0,

Descripcion: se encarga de pasar los parametros de entrada a las variables de entrada, salida y console
             para luego llamar a la funcion para detectar expresiones regulares.
*/
int main(int argc, char *argv[]){
    char entrada[20];
    char salida[20];
    int option;
    int console = 0;
    while((option = getopt(argc, argv, "i:o:b")) != -1){
        switch(option){
            case 'i':
                strcpy(entrada, optarg);
                break;
            case 'o':
                strcpy(salida, optarg);
                break;
            case 'b':
                console = 1;
                break;
        }
    }
    detector(entrada, salida,console);
    return 0;
}