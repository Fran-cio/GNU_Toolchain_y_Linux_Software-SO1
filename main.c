#include "./src/headers/function.h"

int main(int argc,char** argv) {
    int opt;
    int sFlag=0;
    int aFlag=0;
    int jFlag=0;

    while((opt = getopt(argc, argv, "saj")) != -1)
    {
        switch(opt)
        {
            case 's':
                sFlag=1;
                break;
            case 'a':
                aFlag=1;
                break;
            case 'j':
                jFlag=1;
                break;
            case ':':
                printf("option needs a value\n");
                break;
            case '?':
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


    return 0;

}
