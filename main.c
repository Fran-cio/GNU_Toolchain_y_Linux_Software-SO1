#include "./include/function.h"
#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc,char** argv) {
    /*
     * Los flags indican cuales comandos se ingresaron
     */
    int opt;
    int sFlag=0;
    int aFlag=0;
    int jFlag=0;
    int dFlag=0;
    /*
     * Un criterio de diseño fue que cuando no se ingresa parametro se salga de la ejecucion
     */
    if (argc<2) {
        puts("Comando desconocido, ingrese -h para ver los comandos disponibles");
        exit(EXIT_FAILURE);
    } 
    while((opt = getopt(argc, argv, "sajdh")) != -1){
        switch(opt){
            case 's':
                if(sFlag==1){
                    puts("inserte una sola vez el comando");
                    exit(EXIT_FAILURE);
                }
                sFlag=1;
                break;
            case 'a':
                if(aFlag==1){
                    puts("inserte una sola vez el comando");
                    exit(EXIT_FAILURE);
                }
                aFlag=1;
                break;
            case 'j':
                jFlag++;
                break;
            case 'd':
                if(dFlag==1){
                    puts("inserte una sola vez el comando");
                    exit(EXIT_FAILURE);
                }
                dFlag=1;
                break;
            case 'h':
                puts("Las opciones disponibles son:\n\t-s: Datos del punto1\n\t-s -j: Datos de punto1 en formato JSON\n\t-a: Datos de punto2\n\t-a -j: Datos de punto2 en formato JSON\n\t-d: Contenido del archivo filesystem en formato JSON");
                exit(EXIT_FAILURE);
            default: 
                puts("Comando desconocido, ingrese -h para ver los comandos disponibles");
                exit(EXIT_FAILURE);
                break;
        }
    }
    /*
     * Otro criterio de diseño fue que cada comando no se ingrese mas de 1 vez, y ademas que los flags de cJSON
     * se acumulen pudiendo pedir una opcion con formato JSON y otro sin, o los 2 con el formato.
     * 
     * Disclaimer: Por como esta implementado, si quiero ejecutar -a -s y solo quiero -a en formato JSON, no va
     * a ser posible. y voy a tener que ingresar 2 -j.
     */
    if(!sFlag&&!aFlag&&jFlag>0){
        puts("Inserte opcion compatible con formato JSON");
        exit(EXIT_FAILURE);
    }
    if (sFlag){
        puts("\nPunto 1:");
        punto1(jFlag);
        if (jFlag>0) {
            jFlag--;
        }
    }
    if(aFlag){
        puts("\nPunto 2:");
        punto2(jFlag);
        if (jFlag>0) {
            jFlag--;
        }
    }
    if (dFlag) {
        puts("\nFilesystem");
        void* handle = dlopen("libcjson.so",RTLD_LAZY);
        void (*filesystem)();
        if(!handle){
            puts("Fallo al abrir la libreria");
            exit(EXIT_FAILURE);
        }
        dlerror();
        /* 
         * El comando *(void **)(&filesystem) surgio como solucion a un error que lanzaba -pedantic pero
         *desconozco el porque, es la solcion propuesta en stackoverflow
         */
        *(void **)(&filesystem) = dlsym(handle,"filesystem");
        (*filesystem)();
        dlclose(handle);
    }

    return 0;

}
