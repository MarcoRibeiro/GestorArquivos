#include "estatisticas.h"


int getAnoMin(Estatisticas *est){
	return est->anoMin;
}
int getAnoMax(Estatisticas *est){
	return est->anoMax;

}
int getNumLinhas(Estatisticas *est){
	return est->numeroLinhas;
}
int getNumNomes(Estatisticas *est){
	return est->numeroNomes;

}
char* getNomeFicheiro(Estatisticas *est){
	return est->nomeFicheiro;
}

void setAnoMax(Estatisticas *est,int ano){
	est->anoMax=ano;
}

void setAnoMin(Estatisticas *est,int ano){
	est->anoMin=ano;
}

void setNumLinhas(Estatisticas *est,int linhas){
	est->numeroLinhas=linhas;
}

void setNomeFicheiro(Estatisticas *est,char*nome){
	est->nomeFicheiro = nome;
}


void setNumNomes(Estatisticas *est,int nomes){
	est->numeroNomes=nomes;
}


