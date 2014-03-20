

typedef struct autor{
	char * nome;
	int comprimento;
	struct autor * next;
}Autor;

typedef struct arrayAutor{
	struct autor * array[26];
}Autores;

Autores * createAutores();

Autor * getListaAutores(Autores *listaAutores, char * a);


int findIndex(char * autor);


int insert(Autores *listaAutores ,char * autor);
