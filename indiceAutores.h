

typedef struct autor{
	char * nome;
	int comprimento;
	struct autor * next;
}Autor;

typedef struct arrayAutor{
	int size;
	struct autor ** array;
}Autores;




int findIndex(char * autor);

int insert(Autor **listaAutores ,char * autor);
