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






/*typedef struct pnodo
{
	int indice;
	unsigned char* numpag;
	int bitprau;//bit presente o ausente
} *Pag;

typedef struct Nodo{
    Pagina pagina;
    Marco marco;
    struct Nodo *sig;
} *Lista;

Lista vacia(){return NULL;}

Lista cons(Pagina pag, Marco mar, Lista l){
    Lista temp=(Lista)malloc(sizeof(struct Nodo));
    temp->pagina =pag;
	temp->marco =mar;
    temp->sig=l;
    return temp;
}

int esvacia(Lista l){return l==NULL;}

int cavezapag(Lista l){return l->pagina;}
int cavezamar(Lista l){return l->marco;}

Lista resto(Lista l){return l->sig;}

void ImpPag(int pagina){printf("%n",pagina);}
void ImpMar(int marco){printf("%n",marco);}

void ImpElems(Lista l){
    if(!esvacia(l)){
        ImpPag(cavezapag(l));
		ImpMar(cavezamar(l));
        ImpElems(resto(l));
    }
}






typedef struct Nodo
{
	Pag dato;
	struct Nodo *sig;
} *Lista;

typedef struct Nodo2
{
	Vir dato;
	struct Nodo2 *sig;
} *Lista2;

/*Pag conspag(unsigned char ind, unsigned char nump, unsigned char bitpa, Pag pnd)
{
	Pag p = (Pag) malloc(sizeof(struct pnodo));
	p -> indice = ind;
	p -> numpag = nump;
	p -> bitprau = bitpa;
	return p;
}

void bitpresente(Pag pnd)
{
	pnd -> bitprau = 1;
}

void bitausente(Pag pnd)
{
	pnd -> bitprau = 0;
}

Lista vacia()
{
	return NULL;
}

Lista cons(Pag e, Lista l)
{
	Lista t = (Lista) malloc(sizeof(struct Nodo));
	t -> dato = e;
	t -> sig = l;

	return t;
}

int esvacia(Lista l)
{
	return l == NULL;
}


Pag cabeza(Lista l)
{
	return l -> dato;
}

Lista resto(Lista(l))
{
	return l -> sig;
}

*/

