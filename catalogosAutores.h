typedef struct coAutor{
	char * nome;
	int numPublicacoes;
	struct coAutores * next;
}CoAutor;


typedef struct escritor{
	char * nome;
	int numArtigos;
	int numCoAutores;
	struct coAutor * nextCoAutor;
	struct escritor * nextEscritor;
}Escritor;

typedef struct publicacoesPorAno{
	int size;
	struct escritor **tabela;
}PublicacoesPorAno;


PublicacoesPorAno criarTabela(int size);

Escritor criarEscritor(char*nome);

CoAutor criarCoAutor();

void inserirEscritor(PublicacoesPorAno p,Escritor e);

void inserirCoAutor(PublicacoesPorAno p, Escritor e, CoAutor c);

int hashIndex(int ano);

Escritor getEscritoPorAno(PublicacoesPorAno p,char * nome, int ano);

CoAutor* getListaCoAutores(PublicacoesPorAno p,char * nome,int ano);





