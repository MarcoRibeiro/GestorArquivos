#include "indiceAutores.h"
#include "estatisticas.h"
#include "catalogosAutores.h"
#include "menu.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int numAut(char * publicacao) {
	int ind = 0;
	int numautores = 0;
	while (publicacao[ind] != '\0') {

		if (publicacao[ind] == ',') {
			numautores++;

		}

		ind++;
	}
	return numautores;
}
void deletespace(char * word) {
	int i, j;

	for (i = 0; word[i] != '\0'; i++) {
		if (word[0] == ' ') {
			for (j = i; word[j] != '\0'; j++) {
				word[j] = word[j + 1];
			}
		}

	}

}

int main() {
	FILE * ficheiro;
	Estatisticas *est = malloc(sizeof(struct estatisticas));
	Autores *listaAutores = createAutores();
	PublicacoesPorAno * publicacoesPorAno = criarTabela(100);
	NodoAutor * raiz = NULL;
	int status = 0;
	char buff[1024], *nomeAutor;
	int linhas = 0, numAutores, i, numTotalAutores;
	int anoMax = 0, anoMin = 3000;

	char *anoChar;
	int ano;

	char nomeFicheiro[20] = "publicx.txt";
	/* printf("Por favor, insira o nome do ficheiro que pretende analisar!\n");
	 scanf("%s",nomeFicheiro);
	 ficheiro = fopen(nomeFicheiro,"r");
	 */
	ficheiro = fopen("publicx.txt", "r");
	if (ficheiro == NULL ) {
		printf("O ficheiro nao existe!\n");
		return 0;
	} else {
		numTotalAutores = 0;
		while (fgets(buff, 1024, ficheiro)) {

			char * publicacao = buff;

			publicacao = strdup(publicacao);

			numAutores = numAut(buff);
			char * escritores[numAutores];
			i = 0;
			while (i < numAutores) {
				nomeAutor = strsep(&publicacao, ",");
				deletespace(nomeAutor);
				insert(listaAutores, listaAutores->array[findIndex(nomeAutor)],nomeAutor, &status);
				escritores[i] = nomeAutor;
				i++;
				numTotalAutores++;
			}

			anoChar = strsep(&publicacao, "\n");

			deletespace(anoChar);


			ano = atoi(anoChar);
			if (ano) {
				inserirEscritor(publicacoesPorAno, escritores, numAutores, ano);
				if (ano < anoMin) {
					anoMin = ano;
					setAnoMin(est, anoMin);
					if (ano == 0)
						return 0;
				}
				if (ano > anoMax) {
					anoMax = ano;
					setAnoMax(est, anoMax);
				}

				linhas++;
				printf("%d\n", linhas);
			}
		}

		setNumLinhas(est, linhas);
		setNumNomes(est, numTotalAutores);
		setNomeFicheiro(est, nomeFicheiro);

	}
	menu(publicacoesPorAno, est, listaAutores);

	return 1;
}

