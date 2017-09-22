#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int dni;
    int estado;


}EPersona;




/**
 * @brief afirma si la cadena contiene solo caracteres de letras
 * @param char cadena de caracteres a analizar
 * @return retorna 1 si contiene solo letras, o 0 si no contiene  solo letras
 */
int esSoloLetras(char cade[]){
int i=0;
while (cade[i]!= '\0')
{
if (  (cade[i]!=' ') && (cade[i]<'a' || cade[i]>'z') && (cade[i]<'A' || cade[i]>'Z')  )
    return 0;
    i++;
}
    return 1;
}

/**
 * @brief afirma si la cadena contiene solo caracteres de numeros
 * @param char cadena de caracteres a analizar
 * @return int retorna 1 si contiene solo numeros, o 0 si no contiene  solo numeros
 */
int esNumerico(char cade[]){
int i=0;

while (cade[i]!='\0'){

if (cade[i]<'0'|| cade[i]>'9')
    return 0;

    i++;
}
    return 1;
}

/**
 * @brief muestra mensaje por pantalla y ingresa valor a cadena
 * @param char mensaje que se mostrara por pantalla
 * @param char cadena donde se ingresara valor despues del mensaje
 */
void getString (char mensaje[],char input[]){                 //ingreso de cadena

    printf ("%s",mensaje);
    scanf("%s",input);
}

/**
 * @brief se muestra mensaje y se escribe sobre cadena, en caso de que no se escriba numeros, se retorna un valor 0 y no se altera la cadena(input)
 * @param mensaje a mostrar por pantalla
 * @param char input cadena a ingresar
 * @return retorna 1 si contiene solo numeros y escribe en la cadena, retorna 0 si no contiene  solo numeros y no escribe la cadena
 */
int GetStringNumeros (char mensaje[],char input[]){

char aux[256];

      getString(mensaje,aux);
      if(esNumerico(aux)){
        strcpy(input,aux);
        return 1;
      }
return 0;
}


/**
 * @brief se muestra mensaje y se escribe sobre cadena, en caso de que no se escriba solo letras, se retorna un valor 0 y no se altera la cadena(input)
 * @param mensaje a mostrar por pantalla
 * @param char input cadena a ingresar
 * @return retorna 1 si contiene solo letras y escribe en la cadena, retorna 0 si no contiene letras y no escribe la cadena
 */
int GetStringLetras (char mensaje[],char input[]){           //valida que el string ingresado sea solo letras

char aux [256];

    getString(mensaje,aux);
     if (esSoloLetras(aux)){
     strcpy(input,aux);
     return 1;
     }
     return 0;
}


/**
 * @brief Inicializa los valores de estado
 * @param Array EPersona a inicializar
 * @param int elementos del array tipo EPersona
 * @param int valor a inicializar
 */
void inicializarEstado (EPersona persona[],int elementos,int valorAiniciar){      //cambia todos los valores del estado al valor logico -1
int i;
for (i=0;i<elementos;i++){
    persona[i].estado=valorAiniciar;
}
}


/**
 * @brief Compara cadenas, y retorna numero de elemento libre del estado, en caso contrario, retorna -1
 * @param Array EPersona donde sera buscado el valor
 * @param int elementos del array tipo EPersona
 * @param int valor a buscar
 * @return -1 si no hay ocurrencia, o numero de elemento si existe.
 */
int buscarPrimeraOcurrencia(EPersona cadena[],int elementos,int valor){

int i;

for (i=0;i<elementos;i++){
    if(cadena[i].estado==valor)
        return i;
}

return -1;
}



/**
 * @brief Compara cadenas, y retorna numero de elemento libre del DNI, en caso contrario, retorna -1
 * @param Array EPersona donde sera buscado el valor
 * @param int elementos del array tipo EPersona
 * @param int valor a buscar
 * @return -1 si no hay ocurrencia, o numero de elemento si existe.
 */
int buscarDNI(EPersona cadena[],int elementos,int valor){

int i;

for (i=0;i<elementos;i++){
    if(cadena[i].dni==valor)
        return i;
}

return -1;
}

/**
 * @brief Compara nombres del tipo EPersona y ordena por burbujeo todos los valores de la estructura
 * @param Array EPersona donde se comparar los nombres
 * @param int elementos del array tipo EPersona
 */
void burbujaNombres(EPersona arreglo[],int tamanio){



/**
 * @brief Compara valores de elemento entero y retorna el mayor
 * @param Array entero a analizar
 * @param int elementos
 * @return int retorna el valor del elemento mayor
 */



/**
 * @brief compara elementos de vector numerico, y retorna el valor mayor
 * @param Array int a comparar
 * @param int elementos del array
 * @return elemento mayor (positivo)
 */




EPersona aux;
int j;
   for (j=0;j<tamanio-1;j++){
     if (strcmp(arreglo[j].nombre,arreglo[j+1].nombre))

     aux=arreglo[j];
     arreglo[j]=arreglo[j+1];
     arreglo[j+1]=aux;
    }
}
int elMayor(int vec[],int tamanio){
int i;
int mayor=0;


for (i=0; i<tamanio; i++)
{
    if (vec[i]> mayor)
    mayor=vec[i];

}

return mayor;
}



/**
 * @brief recibe 3 contadores enteros y los grafica con *
 * @param int valor 1
 * @param int valor 2
 * @param int valor 3
 */
void mostrarGrafico(int a,int b,int c){

int i,j;
int valores[3]={a,b,c};


int mayor=elMayor(valores,3);

char grafico[mayor][4];



//inicializar con espacios
for (i=0;i<mayor;i++){
     strcpy(grafico[i],"   ");
}

//valor1
for (i=0;i<a;i++)
{
    grafico[i][0]='*';
}
//valor2
for (i=0;i<b;i++)
{
    grafico[i][1]='*';
}
//valor3
for (i=0;i<c;i++)
{
    grafico[i][2]='*';
}


//Imprimir
for (i=0;i<mayor;i++){
for (j=0;j<4;j++){
    printf ("%c    ",grafico[i][j]);
}
        printf ("\n");
}
printf("<18 18<35 35>");




}

#endif // FUNCIONES_H_INCLUDED
