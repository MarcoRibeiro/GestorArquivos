

typedef struct autor{
	char * nome;
	int comprimento;
	struct autor * next;
}Autor;

typedef struct arrayAutor{
	struct autor * array[26];
}Autores;




int findIndex(char * autor);

int insert(Autores *listaAutores ,char * autor);