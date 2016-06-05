#include "main.h"

ALLEGRO_FONT *fonte_titulo, *fonte_opcoes;
ALLEGRO_COLOR cor_selecionado;

enum instrucao { NOVO_JOGO, INSTRUCOES, RECORDES, SAIR };
int opcao_selecionada;

int inicializa_menu();
void desenha_menu();
void menu();


