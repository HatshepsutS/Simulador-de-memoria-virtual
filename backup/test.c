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


int main(){
    List l=nueva();
    l=formar(formar(formar(formar(formar(formar(l,1,11),2,22),3,33),4,44),5,55),6,66);
    printf("PrimPag: %d \n\n",primerPag(l));
    printf("PrimPag: %d \n\n",primerMar(l));
    ImpPag(primerPag(l));
	ImpMar(primerMar(l));
    ImpList(l);
    return 0;
}
