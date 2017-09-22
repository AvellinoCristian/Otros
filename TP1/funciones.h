#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

int Suma (int x,int y)  // Suma los valores A y B, y retorna el resultado entero
{
int resultado;

return resultado=x+y;

}

int Resta (int x,int y) // Resta los valores A y B, y retorna el resultado entero
{
int resultado;

return resultado=x-y;


}

int Multiplicacion (int x,int y) // Resta los valores A y B, y retorna el resultado entero
{
int resultado;

return resultado=x*y;


}

float Divi (int x,int y)
{
    float resultado;

    return resultado=(float)x/y; // divido 2 enteros casteados como flotantes, y retorno un flotante.

}

int facto (int x)
{
    int acumulador=1,i;

    for (i=1;i<=x;i++)
    {
        acumulador=acumulador*i;     //el acumulador multiplica el resultado del mismo contra la i que se repite hasta ser menor igual al ingresado y
    }
    return acumulador;
}



#endif // FUNCIONES_H_INCLUDED
