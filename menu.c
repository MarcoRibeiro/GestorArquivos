#include "estatisticas.h"
#include "indiceAutores.h"
#include "catalogosAutores.h"
#include <stdio.h>

int menu(PublicacoesPorAno *p, Estatisticas *est, Autores *listaAutores) {
	int continuar = 1;
	int ano,anoMin, anoMax,artigos;
	char *nome;
	int opcao, verMais = 1, contadorNomes;
	NodoAutor * autor = NULL, *aux;
	char letra[2];
	while (continuar != 0) {

		printf("-----------------------------------------------------\n");
		printf("1->Dados do Ficheiro!\n");
		printf("2->Artigos por ano!\n");
		printf("3->\n");
		printf("4->\n");
		printf("5->\n");
		printf("6->Lista de Autores com o nome comecado por uma letra!\n");
		printf("7->\n");
		printf("8->\n");
		printf("9->\n");
		printf("10->\n");
		printf("11->\n");
		printf("12->\n");
		printf("13->\n");
		printf("14->\n");
		printf("15-> Sair!\n");
		printf("-----------------------------------------------------\n");
		scanf("%d", &opcao);

		switch (opcao) {
		case 1:
			printf("---------------INFORMAÇÕES DO FICHEIRO---------------\n");
			printf("Nome do Ficheiro: %s\n", getNomeFicheiro(est));
			printf("numero de linhas: %d\n", getNumLinhas(est));
			printf("Numero de nomes lidos:%d\n", getNumNomes(est));
			printf("[%d a %d]\n", getAnoMin(est), getAnoMax(est));
			printf("-----------------------------------------------------\n");
			break;
		case 2:
			printf("-----------------------------------------------------\n");
			anoMin = getAnoMin(est);
			anoMax = getAnoMax(est);
			while (anoMin <= anoMax) {
				if (numArtigosPorAno(p, anoMin) != 0) {
					printf("no ano %d foram publicados %d artigos!\n", anoMin,numArtigosPorAno(p, anoMin));
				}
				anoMin++;
			}
			printf("-----------------------------------------------------\n");
			break;
		case 3:
			printf("Insira o ano!\n");
			scanf("%d", &ano);
//			printf("Insira o nome do escritor:\n");
//			scanf("%s",nome);
			nome="Yan Lei";
			artigos=getArtigosEscrito(p,nome,ano);
			printf("No ano %d o escritor %s publicou %d artigos!\n",ano,nome,artigos);

			break;
		case 4:
		case 5:
		case 6:
			printf("Insira a letra!\n");
			scanf("%s", letra);
			aux = getListaAutores(listaAutores, letra);
			autor = aux;
			printf("Nomes começados pela letra %s:\n", letra);
			contadorNomes = 0;
			verMais = 1;
			while (autor && verMais == 1) {
				contadorNomes++;

				printf("%s\n", autor->nome);
				//autor = autor->next;
				if (contadorNomes == 25) {
					printf("Ver mais?\n");
					printf("0->Nao!\n");
					printf("1->Sim!\n");
					scanf("%d", &verMais);
					contadorNomes = 0;
				}
			}
			break;
		case 7:
		case 8:
		case 9:
		case 10:
		case 11:
		case 12:
		case 13:
		case 14:
		case 15:
			printf("Saiu do programa!\n");
			continuar = 0;
			break;
		default:
			printf("Opcão invalida!\n");
			break;
		}

	}

	return 1;
}
