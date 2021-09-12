#ifndef FUNCIONES
#define FUNCIONES

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdint.h>
#include <unistd.h>
#include "../include/cJSON.h"
//Punto1
void punto1(int jFlag); 
void deKbaMb(int *numero);
void iYii(int *RAM_total, int *RAM_Libre, int *RAM_disponible, int *SwapOcupada);
void iii(char *Cpu, int *Cores, int *Thread);
//Punto2
void punto2(int jFlag);
void strupr(char *texto);
void getter(char ***texto, int *cantpalabras);
 
#endif
