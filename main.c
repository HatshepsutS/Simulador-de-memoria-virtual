#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "lista.h"
#define sizeMV 64 //tamaño de memoria virtual
#define sizeMF 32 //tamaño de memoria física
#define sizePG 4 //tamaño de la página
#define  sizePGBytes 4096
/*int binary(int n){
    int binaryint;
    for(int i=0;n>0;i++){
        if(n%2!=0){
          binaryint = binaryint + (int)pow(10.00,(double)(i));
        }
        n=n/2;
    }
    return (int)binaryint;
}*/
void transformacion_pagina(int pagina, int marco);

void convertir_numero_binario(int numero,  char cantidad_bits, char *cadena);
int main(){

    //Creando la tabla de páginas de la memoria virtual
    int pagina[6][sizeMV/sizePG];
    //printf("\nID\tMemFi\tPA\n");
    for(int i=0; i<(sizeMV/sizePG); i++){
        pagina[0][i]=i;
        pagina[1][i]=0;
        pagina[2][i]=0;
        pagina[3][i]=0;
        pagina[4][i]=0; // presente=1 , ausencia=0
        pagina[5][i]=0; //MemFi Decimal // ocultado
        //printf("%d\t%d%d%d\t%d\t%d\n",pagina[0][i],pagina[1][i],pagina[2][i],pagina[3][i],pagina[4][i],pagina[5][i]);
    }
    //Creando la tabla de marcos de la memoria física
    int marco[7][sizeMF/sizePG];
    //printf("\nID\tMemVi\n");
    for(int j=0; j<(sizeMF/sizePG); j++){
        marco[0][j]=j;
        marco[1][j]=0;
        marco[2][j]=0;
        marco[3][j]=0;
        marco[4][j]=0;
        marco[5][j]=0; //ocupado / no ocupado //ocultado
        marco[6][j]=0; //MemVi Decimal // ocultado
        //printf("%d\t%d%d%d%d\t%d\t%d\n",marco[0][j],marco[1][j],marco[2][j],marco[3][j],marco[4][j],marco[5][j],marco[6][j]);
    }
    printf("\nBienvenido al simulador de memoria virtual :) \n\n");

    List l=nueva(); //Lista se guarda el orden de pagina insertada

    while(1){
        printf("1. Ver estado de memoria \n");
        printf("2. Insertar pagina a la memoria fisica\n");
        printf("Selecion: ");
        int select=0;
        scanf("%d",&select);
        switch(select){
            case 1:
                printf("\n===Tabla de Paginas===");
                printf("\nIDpg\tMemFi\tPA\n");
                for(int k=0; k<(sizeMV/sizePG); k++){
                    printf("%d\t%d%d%d\t%d\n",pagina[0][k],pagina[1][k],pagina[2][k],pagina[3][k],pagina[4][k]);
                }
                printf("\n===Tabla de Marcos===");
                printf("\nIDmr\tMemVi\n");
                for(int m=0; m<(sizeMF/sizePG); m++){
                    printf("%d\t%d%d%d%d\n",marco[0][m],marco[1][m],marco[2][m],marco[3][m],marco[4][m]);
                }
                break;
            case 2:
                printf("Ingrese el numero de la pagina se desea desea insertar a la memoria fisica: ");
                int paginadesea, i=0, pripag, primar, marinsert;
                scanf("%d",&paginadesea);
                if(pagina[4][paginadesea]==1)
                //if(paginadesea==marco[6][(pagina[5][paginadesea])])
                    printf("\n***Ya la pagina %d esta en la memoria fisica***\n",paginadesea);
                else{
                    if(esnueva(l)){
                    marinsert=0;
                    }
                    else{
                        ImpList(l);
                        pripag = primerPag(l);
                        printf("\nprimpag: %d\n",pripag);
                        primar = primerMar(l);
                        printf("\nprimar: %d\n",primar);
                        marinsert = (marinsert+1)%8;
                        printf("\nmarinsert: %d\n",marinsert);
                    }

                    if(marco[5][marinsert]==1){
                        pagina[4][pripag]=0; // apagando P/A de la primera pagina
                        l=desformar(l);
                    }
                    //poner en la lista, id marco, id pagina
                    l=formar(l,paginadesea,marinsert);

                    int marc=marinsert;
                    pagina[4][paginadesea] = 1;
                    pagina[5][paginadesea] = marinsert;
                    pagina[3][paginadesea] = marc%2;
                    marc=marc/2;
                    pagina[2][paginadesea] = marc%2;
                    marc=marc/2;
                    pagina[1][paginadesea] = marc%2;

                    marco[5][marinsert] = 1;
                    //asignando id pagina en la tabla marco
                    marco[6][marinsert] = paginadesea;
                    marco[4][marinsert] = paginadesea%2;
                    paginadesea=paginadesea/2;
                    marco[3][marinsert] = paginadesea%2;
                    paginadesea=paginadesea/2;
                    marco[2][marinsert] = paginadesea%2;
                    paginadesea=paginadesea/2;
                    marco[1][marinsert] = paginadesea%2;
                }


         for(int m=0; m<(sizeMF/sizePG); m++){
                if(paginadesea=marco[6][m])
                transformacion_pagina(paginadesea,marco[6][m]);

            }

                printf("\n===Tabla de Paginas===");
                printf("\nIDpg\tMemFi\tPA\n");
                for(int k=0; k<(sizeMV/sizePG); k++){
                    printf("%d\t%d%d%d\t%d\t%d\n",pagina[0][k],pagina[1][k],pagina[2][k],pagina[3][k],pagina[4][k],pagina[5][k]);
                }
                printf("\n===Tabla de Marcos===");
                printf("\nIDmr\tMemVi\n");
                for(int m=0; m<(sizeMF/sizePG); m++){
                    printf("%d\t%d%d%d%d\t%d\t%d\n",marco[0][m],marco[1][m],marco[2][m],marco[3][m],marco[4][m],marco[5][m],marco[6][m]);
                }
                break;

            default:
                printf("\nPor favor, Elige 1 o 2\n");
        }
    }
    //0110100100->11010100010
return 0;
}


void transformacion_pagina(int pagina, int marco)
{
	int i;
	int bits_tabla = (int)(log10(sizeMV/sizePG)/log10(2)) +1 ;
	int bits_marco = (int)(log10(sizeMF/sizePG)/log10(2)) +1 ;
	int bits_direccion = (int)(log10(sizePG )/log10(2)) +1;


	char tabla_binario[bits_tabla + 1];
	char marco_binario[bits_marco + 1];
	char direccion_binario[bits_direccion + 1];


	convertir_numero_binario(pagina, bits_tabla, tabla_binario);
	convertir_numero_binario(marco, bits_marco, marco_binario);

	for(i = 0; i < sizePGBytes; i++)
	{
		convertir_numero_binario(i, bits_direccion, direccion_binario);
		printf("%s%s\t->\t%s%s\n", tabla_binario, direccion_binario, marco_binario, direccion_binario);
	}


}


void convertir_numero_binario(int numero,  char cantidad_bits, char *cadena)
{
	int corrimiento = 0;

	for(corrimiento = cantidad_bits - 1; corrimiento >= 0; corrimiento--)
	{
		if((numero >> corrimiento) & 0x01)
			cadena[cantidad_bits - (corrimiento + 1)] = '1';
		else
			cadena[cantidad_bits - (corrimiento + 1)] = '0';
	}

	cadena[cantidad_bits] = '\0';

}
