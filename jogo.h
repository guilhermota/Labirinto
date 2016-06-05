#include "main.h"

typedef struct{
	int muro_c;
	int muro_b;
	int muro_e;
	int muro_d;
	int grupo;
} celula;

typedef struct{
	int x;
	int y;
} personagem;

int linhas, colunas;
celula **labirinto;

void le_tamanho();
void inicializa_labirinto();
void gera_labirinto();
int checa_colisao();
void novo_jogo();