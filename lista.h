typedef struct pnodo
{
	int indice;
	unsigned char* numpag;
	int bitprau;//bit presente o ausente
} *Pag;

typedef struct vnodo
{
	int indice;
	unsigned char* numpag;
} *Vir;

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


