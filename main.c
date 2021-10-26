#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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

    //Creando la tabla de páginas de la memoria virtual
    int pagina[5][sizeMV/sizePG];
    print("ID\tMemFi\tPA");
    for(int i=0; i<(sizeMV/sizePG); i++){
        pagina[0][i]=i;
        pagina[1][i]=0;
        pagina[2][i]=0;
        pagina[3][i]=0;
        pagina[4][i]=0; // presente=1 , ausencia=0
        printf("%d\t%d%d%d\t%d\n",pagina[0][i],pagina[1][i],pagina[2][i],pagina[3][i],pagina[4][i]);
    }
    //Creando la tabla de marcos de la memoria física
    int marco[6][sizeMF/sizePG];
    print("ID\tMemVi");
    for(int j=0; j<(sizeMV/sizePG)+1; j++){
        marco[0][j]=j;
        marco[1][j]=0;
        marco[2][j]=0;
        marco[3][j]=0;
        marco[4][j]=0;
        marco[5][j]=0; //ocupado / no ocupado //ocultado
        printf("%d\t%d%d%d%d\n",marco[0][j],marco[1][j],marco[2][j],marco[3][j],marco[4][j]);
    }

    List l=nueva(); //Lista se guarda el orden de pagina insertada

    printf("Bienvenido al simulador de memoria virtual :) \n");
    printf("1. Ver estado de memoria \n");
    printf("2. Insertar pagina a la memoria fisica\n");
    int select=0;
    scanf("%d",&select);

    switch(select){
        case '1':
            print("===Tabla de Paginas===");
            print("\nIDpg\tMemFi\tPA");
            for(int i=0; i<(sizeMV/sizePG); i++){
                printf("%d\t%d%d%d\t%d\n",pagina[0][i],pagina[1][i],pagina[2][i],pagina[3][i],pagina[4][i]);
            }
            print("===Tabla de Marcos===");
            print("\nIDmr\tMemVi");
            for(int j=0; j<(sizeMV/sizePG); j++){
                printf("%d\t%d%d%d%d\n",marco[0][j],marco[1][j],marco[2][j],marco[3][j],marco[4][j]);
            }
            break;
        case '2':
            int paginadesea, i=0;
            scanf("%d",&paginadesea);
            printf("Ingrese el numero de la pagina se desea desea insertar a la memoria física: \n");
            //algoritmo de fallo de página?? si correcto la definicion?
            while(pagina[5][i]!=0){ //hasta se encuentra marco ausencia
                i++;
                if(i==sizeMF/sizePG)
                    break;
            }
            if(i==sizeMF/sizePG){ //en caso no hay marco vacio > sacando primer de la lista
                i=0;//voy a poner al 0 de marco
                int pripag = primerPag(l);
                pagina[4][pripag]=0; // apagando P/A
                l=desformar(l);
            }
            //poner en la lista, id marco, id pagina
            l=formar(l,i,paginadesea);
            //asignando id pagina en la tabla marco
            marco[4][i] = paginadesea%2;
            paginadesea=paginadesea/2;
            marco[3][i] = paginadesea%2;
            paginadesea=paginadesea/2;
            marco[2][i] = paginadesea%2;
            paginadesea=paginadesea/2;
            marco[1][i] = paginadesea%2;
            break;

        default:
            printf("\nPor favor, Elige 1 o 2\n");
    }

    //caso que ya tiene marco asinado -1. activado / 2. desactivado
    //0110100100->11010100010
return 0;
}
