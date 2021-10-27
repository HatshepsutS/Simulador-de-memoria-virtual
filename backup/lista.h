#include <stdio.h>
#include <stdlib.h>
typedef int Pagina;
typedef int Marco;

typedef struct Nodo{
    Pagina pagina;
	Marco marco;
    struct Nodo *sig;
}*ApNodo;

typedef struct{
    ApNodo primero;
    ApNodo ultimo;
}LNodo;

typedef LNodo *List;

List nueva(){
    List t = (List)malloc(sizeof(LNodo));
    t->primero = t->ultimo = NULL;
    return t;
}

int esnueva(List l){
    return l->primero == NULL && l->ultimo == NULL;
}

List formar(List l, Pagina pag, Marco mar){
    ApNodo t = (ApNodo)malloc(sizeof(struct Nodo));
    t->pagina = pag;
	t->marco = mar;
    t->sig = NULL;

    if(esnueva(l))
        l->primero = l->ultimo = t;
    else{
        l->ultimo->sig = t;
        l->ultimo = t;
    }
    return l;
}

List desformar (List l){
    if(l->primero == l->ultimo)
        return nueva();
    else
        l->primero = l->primero->sig;
    return l;
}
Pagina primerPag(List l){
    return l->primero->pagina;
}
Marco primerMar(List l){
    return l->primero->marco;
}
void ImpPag(Pagina pagina){printf("%d",pagina);}
void ImpMar(Marco marco){printf("%d",marco);}

void ImpList(List l){
	List r=nueva();
	if(!esnueva(l)){
        printf("Pagina: ");
		ImpPag(primerPag(l));
        printf("\t");
		printf("Marco: ");
		ImpMar(primerMar(l));
		printf("\n");
		r->primero=l->primero;
		r->ultimo=l->ultimo;
		r=desformar(r);
		ImpList(r);
	}
}