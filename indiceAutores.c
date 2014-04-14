#include "indiceAutores.h"
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int findIndex(char * autor) {

	char fristChar = toupper(autor[0]);
	if (fristChar < 65 || fristChar > 91) {
		return 26;
	} else {
		return fristChar - 65;
	}
}

Autores * createAutores() {
	int ini;
	Autores *listaAutores = malloc(sizeof(struct arrayAutor));
	for (ini = 0; ini < 26; ini++) {
		listaAutores->array[ini] = NULL;
	}
	return listaAutores;
}
NodoAutor* creatNodoAutor(NodoAutor * raiz, char * nome) {
	raiz = (NodoAutor *) malloc(sizeof(struct nodoAutor));
	raiz->comprimento = 0;
	raiz->dir = NULL;
	raiz->esq = NULL;
	raiz->fatBal = 0;
	raiz->nome = nome;
	return raiz;
}


void freeArvore(NodoAutor * autor) {
	if (autor != NULL ) {
		freeArvore(autor->esq);
		freeArvore(autor->dir);
		free(autor);
	}
}

int altura(NodoAutor * autor) {
	if (!autor) {
		return -1;
	} else {
		return autor->fatBal;
	}
}

int max(int n, int m) {
	return n > m ? n : m;
}

NodoAutor * rodarEsqSimples(NodoAutor * autor) {

	NodoAutor * novoAutor = NULL;

	novoAutor = autor->esq;
	autor->esq = novoAutor->dir;
	novoAutor->dir = autor;

	autor->fatBal = max(altura(autor->esq), altura(autor->dir)) + 1;
	novoAutor->fatBal = max(altura(novoAutor->esq), autor->fatBal) + 1;
	return novoAutor;
}

NodoAutor * rodarDirSimples(NodoAutor * autor) {

	NodoAutor * novoAutor = NULL;

	novoAutor = autor->dir;
	autor->dir = novoAutor->esq;
	novoAutor->esq = autor;

	autor->fatBal = max(altura(autor->esq), altura(autor->dir)) + 1;
	novoAutor->fatBal = max(altura(novoAutor->esq), autor->fatBal) + 1;
	return novoAutor;
}

NodoAutor* rodarDirDuplo(NodoAutor * autor) {

	autor->dir = rodarEsqSimples(autor->dir);

	return rodarDirSimples(autor);
}

NodoAutor* rodarEsqDuplo(NodoAutor * autor) {

	autor->esq = rodarDirSimples(autor->esq);

	return rodarEsqSimples(autor);
}

int comparar(const char* s1, const char* s2) {
	for (; *s1 == *s2; ++s1, ++s2) {
		if (*s1 == '\0') {
			return 0;
		}
	}
	if (*s1 < *s2) {
		return -1;
	} else {
		return +1;
	}
}

NodoAutor* inserirAutor(char * novo, NodoAutor * autor) {

	if (!autor) {
		autor = (NodoAutor*) malloc(sizeof(struct nodoAutor));
		if (!autor) {
			fprintf(stderr, "Out of memory!!! (insert)\n");

		} else {
			char * nomeAutor = (char *) malloc(strlen(novo) + 1);
			strcpy(nomeAutor, novo);
			autor->nome = nomeAutor;
			autor->fatBal = 0;
			autor->esq = NULL;
			autor->dir = NULL;
		}
	} else if (comparar(novo, autor->nome) == -1) {
		autor->esq = inserirAutor(novo, autor->esq);
		if (altura(autor->esq)-altura(autor->dir)==2) {
			if (comparar(novo, autor->esq->nome) == -1) {
				autor = rodarEsqSimples(autor);
			} else {
				autor = rodarEsqDuplo(autor);
			}
		}
	} else if (comparar(novo, autor->nome) == 0) {
		return autor;
	} else if (comparar(novo, autor->nome) == 1) {
		autor->dir = inserirAutor(novo, autor->dir);
		if (altura(autor->dir)-altura(autor->esq)==2) {
			if (comparar(novo, autor->dir->nome) == 1) {
				autor = rodarDirSimples(autor);
			} else {
				autor = rodarDirDuplo(autor);
			}
		}
	}

    	autor->fatBal = max(altura(autor->esq), altura(autor->dir)) + 1;
	return autor;

}

void printArvore(NodoAutor *autor){
	if(!autor){
		return;
	}
	printf("%s",autor->nome);

	if(autor->esq != NULL)
		printf("%s",autor->esq->nome);
	if(autor->dir != NULL)
			printf("%s",autor->dir->nome);
	printf("\n");

	printArvore(autor->esq);
	printArvore(autor->dir);
}



NodoAutor * getListaAutores(Autores *listaAutores, char * a) {
	int index = findIndex(a);
	return listaAutores->array[index];

}
