#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <conio.h>
#include <ctype.h>
#include <string.h>
#define TAM 20

#define RUTA "archivoPeliculas.bin"


int agregarPelicula(EMovie movie)
{
    FILE* archivo;


       if ((archivo = fopen(RUTA,"rb+")) == NULL)
        {
      if ((archivo = fopen(RUTA,"wb+")) == NULL)
      {
         printf("Error de archivo");
         return 0;
      }
        }

   do
   {


    printf("\n\tTITULO\n");
    fflush(stdin);
    gets(movie.titulo);

    printf("\tPUNTAJE\n");
    scanf("%d",&movie.puntaje);


    printf("\tGENERO\n");
    fflush(stdin);
    gets (movie.genero);

    printf("\tDURACION\n");
    scanf("%d",&movie.duracion);

    printf("\tDESCRIPCION\n");
    fflush(stdin);
    gets(movie.descripcion);

    printf("\tLINK IMG\n");
    fflush(stdin);
    gets(movie.linkImagen);


    fseek(archivo ,0L, SEEK_END);
    fflush(stdin);
    fwrite(&movie,sizeof(EMovie),1,archivo);

    printf("\nTerminar = S\n");
    fflush(stdin);



   }while(tolower(getche())!='s');

  fclose(archivo);


   return 1;
}

int borrarPelicula(EMovie movie)
{

     FILE* archivo;
     char tituloAUX[50];

       if ((archivo = fopen(RUTA,"rb+")) == NULL)
        {
      if ((archivo = fopen(RUTA,"wb+")) == NULL)
      {
         printf("Error de archivo");
         return 0;
      }
        }

    printf("Nombre de pelicula a borrar\n");
    fflush(stdin);
    gets(tituloAUX);

    rewind(archivo);
    while (!feof(archivo))
    {

        fread(&movie, sizeof(EMovie), 1, archivo);

        if ( strcmp(movie.titulo,tituloAUX)== 0 )
        {


            movie.puntaje=-1;
            strcpy(movie.titulo,"-------BAJA LOGICA-------");
            strcpy(movie.descripcion,"-------BAJA LOGICA-------");
            movie.duracion=-1;
            strcpy(movie.genero,"-------BAJA LOGICA-------");
            strcpy(movie.linkImagen,"-------BAJA LOGICA-------");


            fseek(archivo,(long) (-1)*sizeof(EMovie),SEEK_CUR);
            fflush(stdin);
            fwrite(&movie, sizeof(EMovie), 1, archivo);

            fclose(archivo);
            return 1;
        }

    };
    fclose(archivo);
    return 0;
}

void generarPagina(EMovie listaPelis[TAM],char nombreHtml[])
{
     FILE* archiHTML;
     FILE* archivo;
     EMovie auxPeli;
     int cont=0,i;

       if ((archivo = fopen(RUTA,"rb+")) == NULL)
        {
      if ((archivo = fopen(RUTA,"wb+")) == NULL)
      {
         printf("Error de archivo");
      }
        }

    rewind(archivo);

    while (!feof(archivo))
    {

        fread(&auxPeli, sizeof(EMovie), 1, archivo);

        if (auxPeli.puntaje!=-1) //El puntaje marca la baja logica.
        {
           listaPelis[cont]=auxPeli;
         cont++;
        }

     }


     if ((archiHTML = fopen(nombreHtml,"r+")) == NULL)
        {
      if ((archiHTML = fopen(nombreHtml,"w+")) == NULL)
      {
         printf("Error de archivo");
      }
        }



     rewind(archiHTML);
     for (i=0;i<cont;i++)
     {


         fseek(archivo ,0L, SEEK_END);
         fflush(stdin);

         fprintf(archiHTML,"<article class='col-md-4 article-intro'>");
         fprintf(archiHTML,"<a href='#'>");
          //aca imagen
         fprintf(archiHTML,"<img class='img-responsive img-rounded' src='%s' alt=''>",listaPelis[i].linkImagen);
         //aca titulo
         fprintf(archiHTML,"</a><h3><a href='#'>%s</a>",listaPelis[i].titulo);
         fprintf(archiHTML,"</h3><ul>");
         //genero
         fprintf(archiHTML,"<li>Género:%s</li>",listaPelis[i].genero);
         //puntaje
         fprintf(archiHTML,"<li>Puntaje:%d</li>",listaPelis[i].puntaje);
         //duracion
         fprintf(archiHTML,"<li>Duración:%d</li>",listaPelis[i].duracion);
         //descripccion
         fprintf(archiHTML,"</ul><p>%s</p>",listaPelis[i].descripcion);

         fprintf(archiHTML,"</article></div></div><script src='js/jquery-1.11.3.min.js'></script>");
         fprintf(archiHTML,"<script src='js/bootstrap.min.js'></script>");
         fprintf(archiHTML,"<script src='js/ie10-viewport-bug-workaround.js'></script>");
         fprintf(archiHTML,"<script src='js/holder.min.js'></script>");
         fprintf(archiHTML,"</body></html>");





     }



     fclose(archiHTML);
     fclose(archivo);

}


