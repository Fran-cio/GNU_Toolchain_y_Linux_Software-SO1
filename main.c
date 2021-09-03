#include "./src/headers/function.h"
#include <dlfcn.h>

int main(int argc,char** argv) {
    int opt;
    int sFlag=0;
    int aFlag=0;
    int jFlag=0;
    int dFflag=0;
    if (argc<2) {
        puts("Por favor, ingreso una de las opciones disponibles:\n\t-s\n\t-s -j\n\t-a\n\t-a -j\n\t-d");
    } 
    while((opt = getopt(argc, argv, "sajd")) != -1){
        switch(opt){
            case 's':
                sFlag=1;
                break;
            case 'a':
                aFlag=1;
                break;
            case 'j':
                jFlag=1;
                break;
            case 'd':
                dFflag=1;
                break;
            case '?':
                puts("Opcion no valida, las opciones disponibles son:\n\t-s\n\t-s -j\n\t-a\n\t-a -j\n\t-d");
                break;
        }
    }

    if (sFlag){
        puts("Punto 1:");
        punto1(jFlag);
    }
    else if(aFlag){
        puts("Punto 2:");
        punto2(jFlag);
    }
    else if (dFflag) {
        puts("Filesystem");
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
