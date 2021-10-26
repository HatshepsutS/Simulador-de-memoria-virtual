#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#define sizeMV 64 //tamaño de memoria virtual
#define sizeMF 32 //tamaño de memoria física
#define sizePG 4 //tamaño de la página

int main()
{	

 printf("Bienvenido al simulador de memoria virtual :) \n");
 printf("1. Llenar la memoria RAM \n");
 printf("2. Insertar pagina a la memoria fisica\n"); 
 printf("3. Ver estado de memoria\n"); 
		
Lista ListMV=cons();
for(int i=0;i<(sizeMV/sizePG);i++){

}
