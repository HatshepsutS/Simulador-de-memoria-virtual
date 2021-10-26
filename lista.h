typedef struct pnodo
{
	unsigned char indice;
	unsigned char numpag;
	unsigned char bitprau;//bit presente o ausente
} Pag;

typedef struct Nodo
{
	Pag dato;
	struct Nodo *sig;
} *Lista;

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


