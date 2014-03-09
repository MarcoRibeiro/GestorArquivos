#include "estatisticas.h"
#include <stdio.h>

int menu(Estatisticas *est) {
	int continuar = 1;
	int opcao;

	while (continuar != 0) {

		printf("-----------------------------------------------------\n");
		printf("1->Dados do Ficheiro!\n");
		printf("2->\n");
		printf("3->\n");
		printf("4->\n");
		printf("5->\n");
		printf("6->\n");
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
		scanf("%d",&opcao);






		switch (opcao) {
		case 1:
			printf("---------------INFORMAÇÕES DO FICHEIRO---------------\n");
			printf("Nome do Ficheiro: %s\n", getNomeFicheiro(est));
			printf("numero de linhas: %d\n", getNumLinhas(est));
			printf("Numero de nomes lidos:%d\n", getNumNomes(est));
			printf("Ano maximo:%d\n", getAnoMax(est));
			printf("Ano minimo:%d\n", getAnoMin(est));
			printf("-----------------------------------------------------\n");
			break;
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
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
			continuar=0;
			break;
		default:
			printf("Opcão invalida!\n");
			break;
		}

	}

	return 1;
}
