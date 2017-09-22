#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


#define VALOR 20

int main()
{
    EPersona lista[VALOR];                                                              //Array tipo EPersona de 20 elementos
    char seguir='s',auxNombre[50],auxEdadStr[50],auxDniStr[50],auxEstadoStr[50];        //auxiliares cadena
    int i,lugarLibre=0,opcion=0,conta18=0,conta1835=0,conta35=0;
    int auxEdad,auxDni,auxEstado,bajaDNI,auxBajaDni;

     inicializarEstado(lista,VALOR,-1);                          //Inicializo el valor logico de ESTADO en -1 para indicar que el mismo esta libre.


    while(seguir=='s')
    {
        printf("\n1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:

            lugarLibre=buscarPrimeraOcurrencia(lista,VALOR,-1);

             if (lugarLibre==-1)
             {
                 printf("No quedan lugares libres\n");
                 break;
             }

              printf("\n----AGREGAR PERSONA----\n");
            if (!GetStringLetras("Ingresar Nombre : ",auxNombre))
                {
                    printf ("Solo se pueden ingresar letras\n");
                    break;
                }

            if (!GetStringNumeros("Ingresar EDAD\n",auxEdadStr))
                {
                    printf ("Solo se pueden ingresar valores numericos\n");
                    break;
                }
                auxEdad= atoi(auxEdadStr);

                if (!GetStringNumeros("Ingresar DNI :\n",auxDniStr))
                {
                    printf ("Solo se pueden ingresar valores numericos\n");
                    break;
                }
                auxDni= atoi(auxDniStr);


                strcpy(lista[lugarLibre].nombre,auxNombre);
                lista[lugarLibre].dni=auxDni;
                lista[lugarLibre].edad=auxEdad;
                lista[lugarLibre].estado=5;

                if (lista[lugarLibre].edad>18 && lista[lugarLibre].edad<35)
                conta1835++;
                if (lista[lugarLibre].edad<18)
                    conta18++;
                else
                    conta35++;

                break;
            case 2:
                printf("\n----BORRAR PERSONA----\n");
                puts("Ingresar DNI de la persona\n");
                scanf("%d",&bajaDNI);

                if (buscarDNI(lista,VALOR,bajaDNI)==-1){

                    puts("El DNI no existe!");
                    break;
                }
                auxBajaDni=buscarDNI(lista,VALOR,bajaDNI);
                lista[auxBajaDni].estado=-1;
                puts("Persona Borrada!");
                break;
            case 3:

               burbujaNombres(lista,VALOR);
                for (i=0;i<VALOR;i++){
                    if (lista[i].estado!=-1)
                    printf ("NOMBRE : %s    EDAD : %d    DNI : %d\n",lista[i].nombre,lista[i].edad,lista[i].dni);
                }
                break;
            case 4:


                 mostrarGrafico(conta18,conta1835,conta35);


                break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
