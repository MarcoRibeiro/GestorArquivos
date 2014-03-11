#include "indiceAutores.h"
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int findIndex(char * autor) {

	char fristChar = toupper(autor[0]);

	return fristChar - 65;
}

Autores * createAutores() {
	int ini;
	Autores *listaAutores = malloc(sizeof(struct arrayAutor));
	for (ini = 0; ini < 26; ini++) {
		listaAutores->array[ini] = NULL;
	}
	return listaAutores;
}

int insert(Autores *listaAutores, char * autor) {
	Autor *novoAutor = malloc(sizeof(struct autor));
	Autor *anterior = NULL;
	int index = findIndex(autor);

	novoAutor->nome = autor;
	novoAutor->comprimento = 1;
	novoAutor->next = NULL;

	Autor * aux = listaAutores->array[index];

	while (aux != NULL && strcasecmp(aux->nome, novoAutor->nome) < 0) {
		anterior = aux;
		aux = aux->next;
	}

	if (anterior == NULL ) {
		if (aux == NULL ) {
			listaAutores->array[index] = novoAutor;
		} else {
			listaAutores->array[index] = novoAutor;
			novoAutor->next = aux;
		}

	} else {
		anterior->next = novoAutor;
		novoAutor->next = aux;
	}


	return 1;
}
