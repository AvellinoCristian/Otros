#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0,A=4,B=0;

    while(seguir=='s')
    {


        printf("1- Ingresar 1er operando (A=%d)\n",A);
        printf("2- Ingresar 2do operando (B=%d)\n",B);
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:

                printf ("Ingresar valor A : ");
                scanf ("%d",&A);

                break;
            case 2:

                printf ("Ingresar valor B : ");
                scanf ("%d",&B);

                break;
            case 3:

                printf ("RESULTADO : %d\n",Suma(A,B));

                break;
            case 4:

                printf ("RESULTADO : %d\n",Resta(A,B));

                break;
            case 5:
                 if (B==0)
                    printf ("No se puede dividir por 0\n");  // Mensaje de error ( no valido por que no lo pide )
                 else
                 printf ("RESULTADO : %.2f\n",Divi(A,B));

                break;
            case 6:

                printf ("RESULTADO : %d\n",Multiplicacion(A,B));

                break;
            case 7:

                 printf ("RESULTADO DEL FACTORIAL : %d\n",facto(A));

                break;
            case 8:

                printf ("RESULTADO DE SUMA : %d\n",Suma(A,B));
                printf ("RESULTADO DE RESTA : %d\n",Resta(A,B));
                if (B==0)
                    printf ("RESULTADO DE DIVISION :No se puede dividir por 0\n");
                 else
                printf ("RESULTADO DE DIVISION : %.2f\n",Divi(A,B));
                printf ("RESULTADO DE MULTIPLICACION : %d\n",Multiplicacion(A,B));
                printf ("RESULTADO DEL FACTORIAL : %d\n",facto(A));

                break;
            case 9:
                seguir = 'n';
                break;

        }



}

return 0;
}
