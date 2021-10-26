#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#define sizeMV 64 //tamaño de memoria virtual
#define sizeMF 32 //tamaño de memoria física
#define sizePG 4 //tamaño de la página

int binary(int n){
    int binaryint;
    for(int i=0;n>0;i++){
        if(n%2!=0){
          binaryint = binaryint + (int)pow(10.00,(double)(i));
        }
        n=n/2;
    }
    return (int)binaryint;
}


void asignarproceso(int numpagina){
    //avanza hasta encontrar bitprau == 0 con for iteración
    
    p -> numpag = binarycuatro(numpagina);
    p -> bitprau = 1;
    //si todos itprau == 1
    
}

int main()
{	

 printf("Bienvenido al simulador de memoria virtual :) \n");
 printf("1. Llenar la memoria RAM \n");
 printf("2. Insertar pagina a la memoria fisica\n"); 
 printf("3. Ver estado de memoria\n"); 


int pagina[6][sizeMV/sizePG];

//Creando la tabla de la memoria virtual
for(int i=0; i<(sizeMV/sizePG); i++){
    pagina[0][i]=i;
    pagina[1][i]=0;
    pagina[2][i]=0;
    pagina[3][i]=0;
    pagina[4][i]=0;
    pagina[5][i]=0;
    printf("%d  %d%d%d%d  %d\n",pagina[0][i],pagina[1][i],pagina[2][i],pagina[3][i],pagina[4][i],pagina[5][i]);
}


		
Pag p = (Pag) malloc(sizeof(struct pnodo));
for(int i=0;i<(sizeMV/sizePG);i++){
	p -> indice = i;
	p -> numpag = "0000";
	p -> bitprau = 0;
    Lista ListMV=cons(p,vacia());
}

Vir v = (Vir) malloc(sizeof(struct vnodo));
for(int i=0;i<(sizeMF/sizePG);i++){
	p -> indice = i;
	p -> numpag = "000";
	p -> bitprau = 0;
    Lista ListMV=cons(p,vacia());
}

return 0;
}