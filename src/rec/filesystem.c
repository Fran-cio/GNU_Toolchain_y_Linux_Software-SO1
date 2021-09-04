#include <dlfcn.h>
#include <stdio.h>
#include <unistd.h>
#include "../headers/cJSON.h"
#include <stdlib.h>

void filesystem(){
    char texto1[20],texto2[20];
    FILE *archivo1;
    /* 
     *Se crea un JSON y se le agrega un objeto al cual se les va a agregar las palabras extraidas 
     */
    cJSON *ruta= cJSON_CreateObject();
    cJSON *filesystem;
    cJSON_AddItemToObject(ruta,"filesystem",filesystem=cJSON_CreateObject());
    
    archivo1 = fopen("/proc/filesystems", "r");
    /*
     * A medida que se extraen las palabras se agregan al objeto filesystem
     */
    while (fscanf(archivo1, "%s %s", texto1, texto2)!=EOF) {
        cJSON_AddStringToObject(filesystem, texto1,texto2);    
    };
    /* 
     *Baraje varios formatos de impresion y este fue el mas simple de implemetar complementado con el que mejor
     *me parecio que exponia el contenido en el archivo. 
     */
    fclose(archivo1);
    puts(cJSON_Print(ruta));
    return;
}
