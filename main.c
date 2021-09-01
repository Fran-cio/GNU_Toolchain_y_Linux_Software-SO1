#include "./src/headers/function.h"
#include <stdio.h>
#include <string.h>
 
int main(int argc,char** argv) {
    for(int arg=1;arg<argc;arg++){
        if (!strcmp(argv[arg],"-s")){
            puts("Punto 1:");
            int RAM_total, RAM_libre, RAM_disponible,SwapOcupada;

            iYii(&RAM_total,&RAM_libre,&RAM_disponible,&SwapOcupada);//Metodo que devuelve mediante puntero los valores requeridos
            printf("i.\nla Ram disponible es: %dMb\nla Ram libre es: %dMb\nla Ram total es: %dMb\n\nii.\nLa Swap Ocupada es: %dKb\n"
            ,RAM_disponible,RAM_libre,RAM_total,SwapOcupada);

            char *Cpu=(char*)malloc(sizeof(char)*64);//No hay un criterio para alocar esta cantidad de memoria, el unico fin es que la info del cpu entre
            int Cores,Thread;

            iii(Cpu,&Cores,&Thread);//Metodo que devuelve mediante puntero los valores requeridos
            printf("\niii.\nCpu:%s \nCantidad de Cores: %d \nCantidad de Threads por Core: %d",Cpu,Cores,Thread);

            free(Cpu);
        }
        else if(!strcmp(argv[arg],"-a")){
            puts("\n\n");
            puts("Punto 2:");

            char **texto;
            texto=(char**) malloc(sizeof(char*));
            int cantpalabras=0;

            punto2(&texto,&cantpalabras);

            for(int i=0;i<cantpalabras ; i++){
                puts(texto[i]);
            }

        free(texto);//libero memoria
        }
    }
    return 0;
}
