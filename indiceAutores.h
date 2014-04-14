

typedef struct nodoAutor{
	char * nome;
	int comprimento;
	struct nodoAutor * dir;
	struct nodoAutor * esq;
	int fatBal;
}NodoAutor;

typedef struct arrayAutor{
	struct nodoAutor * array[27];
}Autores;

Autores * createAutores();

NodoAutor* creatNodoAutor(NodoAutor * raiz, char * nome);

NodoAutor * getListaAutores(Autores *listaAutores, char * a);


int findIndex(char * autor);


void insert(Autores *listaAutores, NodoAutor* raiz, char * autor, int status);
