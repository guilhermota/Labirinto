#include "jogo.h"

void le_tamanho(){
	linhas = 10;
	colunas = 10;
}

void inicializa_labirinto(){
	int i, j;
	le_tamanho();
	labirinto = (celula **)calloc(linhas, sizeof(celula*));
	for (i = 0; i < linhas; i++)
	{
		labirinto[i] = (celula *)calloc(colunas, sizeof(celula));
	}
}

void gera_labirinto(){
	int i = 0, j = 0, g = 1;
	//Cria primeira linha
	for (j = 0; j < colunas - 1; j++){
		labirinto[0][j].grupo = g++;
		if (rand() % 2 == 0){
			labirinto[0][j].muro_d = 1;
		}
		else{
			labirinto[0][j + 1].grupo = labirinto[0][j].grupo;
		}

		printf("Linha 1: %d %d %d %d %d\n", labirinto[i][j].grupo, labirinto[i][j].muro_b, labirinto[i][j].muro_c, labirinto[i][j].muro_d, labirinto[i][j].muro_e);
	}

	//Cria linhas intermediarias

	//Cria ultima linha

}

int checa_colisao(){

}

void novo_jogo(){
	inicializa_labirinto();
	gera_labirinto();
	for (int i = 0; i < linhas; i++)
	{
		for (int j = 0; j < colunas; j++)
		{
			if (labirinto[i][j].muro_e == 1 || labirinto[i][j].muro_d == 1) printf("|");
			if (labirinto[i][j].muro_b == 1) printf("_");
			//printf("%d %d %d %d %d\n", labirinto[i][j].grupo, labirinto[i][j].muro_b, labirinto[i][j].muro_c, labirinto[i][j].muro_d, labirinto[i][j].muro_e);
		}
		printf("\n");
	}
	for (int i = 0; i < linhas; i++)
	{
		free(labirinto[i]);
	}
	free(labirinto);

	return;
}