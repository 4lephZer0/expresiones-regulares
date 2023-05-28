#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

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
void calcRegular(char* const cadena, int* opciones, FILE* fichero2){

    for (int i = 0; i < strlen(cadena) + 1; i++){
        

        if(i + 3 >= strlen(cadena)){
            
            
            fprintf(fichero2, "%s No\n", cadena);
            opciones[0] = opciones[0] + 1;
            opciones[2] = opciones[2] + 1;
            
            i = strlen(cadena);
        }

        else if (cadena[i] == 'G'){

            if(cadena[i+1] == 'T'){

                char* cadenaAux = malloc(sizeof(char) * 60);
                strcpy(cadenaAux, cadena + i+1);
                
                for (int j = 0; j < strlen(cadenaAux); j++){

                    if(cadenaAux[j] == 'C'){

                        fprintf(fichero2, "%s Si\n", cadena);
                        opciones[1] = opciones[1] + 1;
                        opciones[2] = opciones[2] + 1;
                        free(cadenaAux);
                        i = strlen(cadena);
                        
                    }

                    if(cadenaAux[j] == 'G' || cadenaAux[j] == 'A'){

                        free(cadenaAux);
                        break;
                    }
                }  
            } 
        }
    }
}

/*
Entrada: fichero: fichero de lectura.
         fichero2: fichero de salida.
         console: valor que se encarga de imprimir en consola segun la flag -b

Salida: al ser una funcion void no retorna nada.

Descripcion: calcular es una funcion que se encarga tanto, de llamar a calcRegular, como de
escribir las ultimas 3 lineas del archivo (las expresiones que son o no son regulares y el total)
*/
void calcular(FILE* fichero, FILE* fichero2, int console){

    char cadena[60];

    int* opciones = malloc(sizeof(int)*3);
    opciones[0] = 0;
    opciones[1] = 0;
    opciones[2] = 0;

    while (fgets(cadena, 60, fichero) != NULL) {
        if (strlen(cadena) > 2){
            calcRegular(cadena, opciones, fichero2);
        }
    }

    if (console == 1){
        printf("\nTotal de expresiones que Si son regulares: %d\n", opciones[1]);
        printf("Total de expresiones que No son regulares: %d\n", opciones[0]);
        printf("Total de lineas leidas: %d", opciones[2]);
    }
    
    fprintf(fichero2, "\n\nTotal de expresiones que Si son regulares: %d\n", opciones[1]);
    fprintf(fichero2, "Total de expresiones que Ni son regulares: %d\n", opciones[0]);
    fprintf(fichero2, "Total de lineas leidas: %d", opciones[2]);
    free(opciones);
    
}
/*
Entrada: entrada: nombre del archivo de lectura.
         salida: nombre del archivo de salida.
         console: valor que se encarga de imprimir en consola segun la flag -b

Salida: al ser una funcion void no retorna nada.

Descripcion: detector es una funcion que se encarga tanto, de llamar a calcular, como de
             abrir los archivos de entrada y salida; y tambien de cerrar dichos archivos.
*/
void detector(char* const entrada, char* const salida, int console){

    FILE* fichero;
    FILE* fichero2;

    fichero = fopen(entrada, "r+");
    fichero2 = fopen(salida, "w+t");
    rewind(fichero);
    calcular(fichero, fichero2, console);
    fclose(fichero);
    fclose(fichero2);
}