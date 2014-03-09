

typedef struct estatisticas{
	int anoMin;
	int anoMax;
	int numeroLinhas;
	int numeroNomes;
	char * nomeFicheiro;
}Estatisticas;

int getAnoMin(Estatisticas *est);
int getAnoMax(Estatisticas *est);
int getNumLinhas(Estatisticas *est);
int getNumNomes(Estatisticas *est);
char* getNomeFicheiro(Estatisticas *est);

void setAnoMin(Estatisticas *est,int ano);
void setAnoMax(Estatisticas *est,int ano);
void setNumLinhas(Estatisticas *est,int linhas);
void setNomeFicheiro(Estatisticas *est,char*nome);
void setNumNomes(Estatisticas *est,int nomes);
