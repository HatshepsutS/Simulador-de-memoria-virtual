typedef struct pnodo
{
	int indice;
	unsigned char* numpag;
	int bitprau;//bit presente o ausente
} *Pag;







typedef struct Nodo{
    int pagina;
    int marco;
    struct Nodo *sig;
} *Lista;


Lista vacia(){return NULL;}

Lista cons(int pag, int mar, Lista l){
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
}*/

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


