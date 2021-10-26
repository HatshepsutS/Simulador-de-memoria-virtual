typedef struct pnodo
{
	unsigned char indice;
	unsigned char numpag;
	unsigned char bitprau;//bit presente o ausente
} *Pag;

typedef struct Nodo
{
	Pag dato;
	struct Nodo *sig;
} *Lista;

Pag conspag(unsigned char ind, unsigned char nump, unsigned char bitpa, Pag pnd)
{
	Pag p = (Pag) malloc(sizeof(struct pnodo));
	p -> indice = ind;
	p -> numpag = nump;
	p -> bitprau = bitpa;
	return p;
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


