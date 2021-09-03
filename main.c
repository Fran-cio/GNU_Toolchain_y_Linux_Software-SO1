#include "./src/headers/function.h"
#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc,char** argv) {
    int opt;
    int sFlag=0;
    int aFlag=0;
    int jFlag=0;
    int dFlag=0;
    if (argc<2) {
        puts("Por favor, ingreso una de las opciones disponibles:\n\t-s\n\t-s -j\n\t-a\n\t-a -j\n\t-d");
        exit(EXIT_FAILURE);
    } 
    while((opt = getopt(argc, argv, "sajd")) != -1){
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
            default: 
                puts("Opcion no valida, las opciones disponibles son:\n\t-s\n\t-s -j\n\t-a\n\t-a -j\n\t-d");
                exit(EXIT_FAILURE);
                break;
        }
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
        *(void **)(&filesystem) = dlsym(handle,"filesystem");
        (*filesystem)();
        dlclose(handle);
    }

    return 0;

}
