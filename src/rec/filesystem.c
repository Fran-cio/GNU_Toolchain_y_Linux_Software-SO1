#include <dlfcn.h>
#include <stdio.h>
#include <unistd.h>
#include "../headers/cJSON.h"
#include <stdlib.h>

void filesystem(){
    char texto1[20],texto2[20];
    FILE *archivo1;

    cJSON *ruta= cJSON_CreateObject();
    cJSON *filesystem;
    cJSON_AddItemToObject(ruta,"filesystem",filesystem=cJSON_CreateObject());
    
    archivo1 = fopen("/proc/filesystems", "r");

    while (fscanf(archivo1, "%s %s", texto1, texto2)!=EOF) {
        cJSON_AddStringToObject(filesystem, texto1,texto2);    
    };
    fclose(archivo1);
    puts(cJSON_Print(ruta));
    return;
}
