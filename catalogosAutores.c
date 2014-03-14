#include "catalogosAutores.h"
#include <stdlib.h>

PublicacoesPorAno * criarTabela(int size){

	PublicacoesPorAno * totalPubli = NULL;
	int i;

	if(size<1) return NULL;

	if((totalPubli = malloc(sizeof(struct publicacoesPorAno)))==NULL) return NULL;

	if((totalPubli->tabela = malloc(sizeof(struct escritor)*size))==NULL) return NULL;

	for(i=0;i<size;i++){
		totalPubli->tabela[i]=NULL;
	}

	totalPubli->size = size;

	return totalPubli;
}

Escritor *criarNovoEscritor(char*nome){
	Escritor *aux = malloc(sizeof(struct escritor));
	aux->nome=nome;
	aux->numArtigos=1;
	aux->numCoAutores=0;
	aux->nextCoAutor=NULL;
	aux->nextEscritor=NULL;
	return aux;
}

CoAutor* criarNovoCoAutor(char * nome){
	CoAutor *aux = malloc(sizeof(struct coAutor));
	aux->nome=nome;
	aux->numPublicacoes=1;
	aux->next = NULL;
	return aux;
}

void inserirEscritor(PublicacoesPorAno p,char **escritores,int ano){
	int index = hashIndex(ano);





}

void inserirCoAutor(PublicacoesPorAno p, Escritor e, CoAutor c){

}

int hashIndex(int ano){

	return ano-1968;
}

Escritor* getEscritoPorAno(PublicacoesPorAno p,char * nome, int ano){

}

int getArtigosEscrito(PublicacoesPorAno p,char * nome, int ano){

}

CoAutor* getListaCoAutores(PublicacoesPorAno p,char * nome,int ano){

}

int numArtigosPorAno(PublicacoesPorAno p,int ano){

}

