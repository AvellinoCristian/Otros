#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <conio.h>
#include <ctype.h>
#include <string.h>


#define TAM 20
#define RUTA "archivoPeliculas.bin"


int main()
{
    char seguir='s';
    int opcion=0;
    EMovie peli;
    EMovie lista[TAM];

    while(seguir=='s')
    {
        system("cls");
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Generar pagina web\n");
        printf("4- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:

               if ( agregarPelicula(peli) == 1 )
                {
                    printf("\nDATOS CARGADOS CON EXITO...\n\n");
                    system("PAUSE");
                }
                else
                {
                   printf("ERROR AL CARGAR...\n\n");
                   system("PAUSE");
                }

                break;
            case 2:
                if  (  borrarPelicula(peli)==1 )
                {
                    printf("DATOS BORRADOS CON EXITO...\n\n");
                    system("PAUSE");
                }
                else
                    {
                    printf("ERROR AL BORRAR...\n\n");
                    system("PAUSE");
                    }

                break;
            case 3:

                generarPagina(lista,"listaDeWebs.html");

               break;
            case 4:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
