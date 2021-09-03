#include "../headers/function.h"
//Pasa a mayusculas los valores en un string
void punto2(int jFlag){
    char **texto;
    texto=(char**) malloc(sizeof(char*));
    int cantpalabras=0;

    getter(&texto,&cantpalabras);
    if(!jFlag){
        for(int i=0;i<cantpalabras ; i++){
            puts(texto[i]);
        }
    }else {
        cJSON *ruta= cJSON_CreateObject();
        cJSON *punto2;
        cJSON_AddItemToObject(ruta,"punto 2", punto2=cJSON_CreateArray()); 

        for(int i=0;i<cantpalabras ; i++){
            cJSON_AddItemToArray(punto2,cJSON_CreateString(texto[i]));
        }
        puts(cJSON_Print(ruta));
    }
    free(texto);//libero memoria

}

void strupr ( char *texto )
{
    while( *texto )
    {
        *texto=toupper( *texto );
        texto++;
    }
}

void getter(char ***texto,int *cantpalabras){
    FILE *archivo;
    char *temp;
    archivo=fopen("/proc/version","r");

    /*
     * guardo en una variable el tamaño del archivo al cual apunta, como el texto
     * posee solo texto, la idea es obtener almenos, la memoria minima necesaria
     */
    int longitud= sizeof(*archivo);
    temp= (char*)malloc(sizeof (char )*longitud);
    fgets(temp,longitud,archivo);//con fgets guardo en un string la cadena de caracteres del archivo
    fclose(archivo);

    /*
     * aprovechamos el arreglo dinamico y realocamos la memoria, y colocamos unicamente
     * el texto que contine.
     */
    temp=realloc(temp, sizeof(char)*strlen(temp));
    strupr(temp);//Esto me sorprendio, tuve que implemetar el metodo strupr, hubiera jurado que estaba en la lib strings.h

    /*
     * Esta funcion "tokeniza" el string en espacios segun el char que le pases
     * en este caso separamos cuando aparece un espacio
     */
    temp = strtok(temp, " ");

    int i=0;

    while( temp != NULL ) {
        /*
         * Este realloc va generando alocacion de memoria en base a medida que agregamos palabras
         */
        if(i!=0){
            (*texto)=(char**) realloc(*texto,sizeof(char*)*(i+1));
        }
        (*texto)[i]=temp;
        i++;
        /*
         * Cuando pasamos como parametro NULL va pasando de token a token
         */
        temp = strtok(NULL, " ");
    }
    //Referencia: https://www.tutorialspoint.com/c_standard_library/c_function_strtok.htm

    /*
     * Genero un contador para posteriormente hacer el for()
     */
    *cantpalabras=i;
}
