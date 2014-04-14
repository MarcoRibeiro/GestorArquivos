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
void rodarEsq(NodoAutor * no,int status){

	NodoAutor * b,*c;
	b=no->dir;
	if(b->fatBal==-1){
		no->dir = b->esq;
		b->esq = no;
		no->fatBal=0;
		no=b;
	}else{
		c=b->esq;
		b->esq = c->dir;
		c->dir=b;
		no->dir = c->esq;
		c->esq=no;
		if(c->fatBal==-1){
			no->fatBal=1;
		}else{
			no->fatBal=0;
		}
		if(c->fatBal==1){
			b->fatBal=-1;
		}else{
			b->fatBal=0;
		}
		no=c;
	}
	no->fatBal=0;
	status= 0;


}
void rodarDir(NodoAutor * no,int status){
	NodoAutor * b,*c;
	b=no->esq;
	if(b->fatBal==-1){
		no->esq = b->dir;
		b->dir = no;
		no->fatBal=0;
		no=b;
	}else{
		c=b->dir;
		b->dir = c->esq;
		c->esq=b;
		no->esq = c->dir;
		c->dir=no;
		if(c->fatBal==-1){
			no->fatBal=1;
		}else{
			no->fatBal=0;
		}
		if(c->fatBal==1){
			b->fatBal=-1;
		}else{
			b->fatBal=0;
		}
		no=c;
	}
	no->fatBal=0;
	status= 0;

}



void insert(Autores *listaAutores, NodoAutor *raiz, char * autor, int status) {
	int index = findIndex(autor);
	//raiz = listaAutores->array[index];

	if (raiz == NULL ) {
		raiz = creatNodoAutor(raiz, autor);
		status = 1;
	} else if (strcasecmp(raiz->nome, autor) == 0) {
		printf("repetido!!\n");
		return;
	} else if (strcasecmp(raiz->nome, autor) > 0) {
		insert(listaAutores, raiz->esq, autor,status);
		if (status == 1) {
			switch (raiz->fatBal) {
			case 1: raiz->fatBal = 0; status =0; break;
			case 0: raiz->fatBal = -1; break;
			case -1 : rodarDir(raiz,status); break;
			}
		}
	} else {
		insert(listaAutores, raiz->dir, autor,status);
		if (status == 1) {
			switch (raiz->fatBal) {
			case -1 : raiz->fatBal = 0; status = 0; break;
			case 0 : raiz->fatBal = 1; break;
			case 1 : rodarEsq(raiz,status);break;
			}
		}
	}
	listaAutores->array[index] = raiz;
}





NodoAutor * getListaAutores(Autores *listaAutores, char * a) {
	int index = findIndex(a);
	return listaAutores->array[index];

}
