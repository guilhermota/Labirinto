#include "menu.h"

int inicializa_menu(){
	fonte_titulo = al_load_ttf_font("C:/Labirinto/fontes/pirulen.ttf", 50, 0);
	fonte_opcoes = al_load_ttf_font("C:/Labirinto/fontes/kristen.ttf", 36, 0);
	if (!fonte_titulo || !fonte_opcoes)
	{
		printf("\nFalha ao carregar arquivo da fonte de texto!!!");
		return 0;
	}

	cor_selecionado = al_map_rgb(0, 150, 150);

	opcao_selecionada = 0;

	return 1;
}

void desenha_menu(ALLEGRO_DISPLAY *display){
	inicializa_menu();
	al_draw_text(fonte_titulo, al_map_rgb(255, 255, 255), 640/2, 480/4, ALLEGRO_ALIGN_CENTER, "LABIRINTO");
	al_draw_line(100, 170, 540, 170, al_map_rgb(255,255,255), 5);

	if (opcao_selecionada == NOVO_JOGO) al_draw_text(fonte_opcoes, cor_selecionado, 640 / 2, 480 / 2, ALLEGRO_ALIGN_CENTER, "NOVO JOGO");
	else al_draw_text(fonte_opcoes, al_map_rgb(255, 255, 255), 640 / 2, 480 / 2, ALLEGRO_ALIGN_CENTER, "NOVO JOGO");
	al_draw_text(fonte_opcoes, al_map_rgb(255, 255, 255), 640 / 2, 480 / 2 + 40, ALLEGRO_ALIGN_CENTER, "INSTRUCOES");
	al_draw_text(fonte_opcoes, al_map_rgb(255, 255, 255), 640 / 2, 480 / 2 + 76, ALLEGRO_ALIGN_CENTER, "RECORDES");
	al_draw_text(fonte_opcoes, al_map_rgb(255, 255, 255), 640 / 2, 480 / 2 + 112, ALLEGRO_ALIGN_CENTER, "SAIR");
}
