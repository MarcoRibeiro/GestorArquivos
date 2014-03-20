#include "catalogosAutores.h"
#include <stdlib.h>
#include <string.h>

PublicacoesPorAno * criarTabela(int size) {

	PublicacoesPorAno * totalPubli = NULL;
	int i;

	if (size < 1)
		return NULL ;

	if ((totalPubli = malloc(sizeof(struct publicacoesPorAno))) == NULL )
		return NULL ;

	if ((totalPubli->tabela = malloc(sizeof(struct escritor) * size)) == NULL )
		return NULL ;

	if ((totalPubli->numArtigos = malloc(sizeof(struct escritor) * size)) == NULL )
			return NULL ;


	for (i = 0; i < size; i++) {
		totalPubli->tabela[i] = NULL;
	}
	for (i = 0; i < size; i++) {
		totalPubli->numArtigos[i] = 0;
	}

	totalPubli->size = size;
	return totalPubli;
}

Escritor *criarNovoEscritor(char*nome) {
	Escritor *aux = malloc(sizeof(struct escritor));
	aux->nome = nome;
	aux->numArtigos = 1;
	aux->numCoAutores = 0;
	aux->nextCoAutor = NULL;
	aux->nextEscritor = NULL;
	return aux;
}

CoAutor* criarNovoCoAutor(char * nome) {
	CoAutor *aux = malloc(sizeof(struct coAutor));
	aux->nome = nome;
	aux->numPublicacoes = 1;
	aux->next = NULL;
	return aux;
}

void inserirEscritor(PublicacoesPorAno *p, char **escritores, int tamanho,
		int ano) {
	int index = hashIndex(ano);
	int i = 0;
	Escritor * anterior = NULL;
	Escritor * aux = p->tabela[index];
	Escritor * novo;
	p->numArtigos[index]++;
	while (i < tamanho) {
		novo = criarNovoEscritor(escritores[i]);
		while (aux != NULL && strcasecmp(aux->nome, novo->nome) <= 0) {
			anterior = aux;
			aux = aux->nextEscritor;
		}

		if (anterior == NULL ) {

			if (aux == NULL ) {
				p->tabela[index] = novo;
			} else {
				if (strcasecmp(aux->nome, novo->nome) != 0) {
					p->tabela[index] = novo;
					novo->nextEscritor = aux;
				} else {
					aux->numArtigos++;
				}
			}

		} else {
			if (strcasecmp(anterior->nome, novo->nome) != 0) {
				anterior->nextEscritor = novo;
				novo->nextEscritor = aux;

			} else {
				anterior->numArtigos++;
			}
		}

		i++;
	}

}

void inserirCoAutor(PublicacoesPorAno *p, Escritor e, CoAutor c) {

}

int hashIndex(int ano) {

	return ano - 1968;
}

Escritor* getEscritoPorAno(PublicacoesPorAno *p, char * nome, int ano) {

}

int getArtigosEscrito(PublicacoesPorAno *p, char * nome, int ano) {
	Escritor * aux = p->tabela[hashIndex(ano)];

	while(strcasecmp(aux->nome,nome)!=0){
		aux=aux->nextEscritor;
	}

	return aux->numArtigos;

}

CoAutor* getListaCoAutores(PublicacoesPorAno *p, char * nome, int ano) {

}

int numArtigosPorAno(PublicacoesPorAno *p, int ano) {

	int numAr = p->numArtigos[hashIndex(ano)];

	return numAr;

}


