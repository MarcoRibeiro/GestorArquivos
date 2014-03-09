#include "indiceAutores.h"
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int findIndex(char * autor) {

	char fristChar = toupper(autor[0]);

	return fristChar - 65;
}

int insert(Autor **listaAutores, char * autor) {
	Autor *novoAutor = malloc(sizeof(struct autor));
	Autor *anterior = NULL;
	int index = findIndex(autor);

	novoAutor->nome = autor;
	novoAutor->comprimento = 1;
	novoAutor->next = NULL;

	if (listaAutores[index] == NULL ) {
		listaAutores[index] = novoAutor;
	} else {
		Autor *aux = listaAutores[index];
		while (aux) {
			if (strcasecmp(aux->nome, novoAutor->nome) == 0) {
				aux = NULL;

			} else if (strcasecmp(aux->nome, novoAutor->nome) < 0) {
				anterior = aux;
				aux = aux->next;
				if (anterior->next == NULL ) {
					anterior->next = novoAutor;
				}
			} else {
				if (anterior == NULL ) {
					novoAutor->next = aux;
					listaAutores[index] = novoAutor;

					aux = NULL;
				} else {
					anterior->next = novoAutor;
					novoAutor->next = aux;

					aux = NULL;
				}

			}

		}
		/*while (aux != NULL && strcasecmp(aux->nome, novoAutor->nome) < 0) {
		 anterior = aux;
		 aux = aux->next;
		 }

		 if (strcasecmp(anterior->nome, novoAutor->nome) > 0) {

		 if (anterior->next == NULL ) {
		 anterior->next = novoAutor;
		 } else if (anterior == NULL ) {
		 novoAutor->next = aux;
		 listaAutores[index] = novoAutor;

		 } else {
		 anterior->next = novoAutor;
		 novoAutor->next = aux;

		 }

		 } else {
		 anterior->comprimento++;

		 }

		 }*/
	}

	return 1;
}
