#include "menu.h"
#include "jogo.h"

int inicializa_menu(){
	fonte_titulo = al_load_ttf_font("C:/Labirinto/fontes/pirulen.ttf", 50, 0);
	fonte_opcoes = al_load_ttf_font("C:/Labirinto/fontes/kristen.ttf", 36, 0);
	if (!fonte_titulo || !fonte_opcoes)
	{
		//printf("\nFalha ao carregar arquivo da fonte de texto!!!");
		return 0;
	}

	cor_selecionado = al_map_rgb(0, 0, 255);

	return 1;
}

void desenha_menu(){
	al_draw_text(fonte_titulo, al_map_rgb(255, 255, 255), 640/2, 480/4, ALLEGRO_ALIGN_CENTER, "LABIRINTO");
	al_draw_line(100, 170, 540, 170, al_map_rgb(255,255,255), 5);

	if (opcao_selecionada == NOVO_JOGO)
	{
        al_draw_text(fonte_opcoes, cor_selecionado, 640 / 2, 480 / 2, ALLEGRO_ALIGN_CENTER, "NOVO JOGO");
	}
	else al_draw_text(fonte_opcoes, al_map_rgb(255, 255, 255), 640 / 2, 480 / 2, ALLEGRO_ALIGN_CENTER, "NOVO JOGO");
    if (opcao_selecionada == INSTRUCOES)
    {
        al_draw_text(fonte_opcoes, cor_selecionado, 640 / 2, 480 / 2 + 40, ALLEGRO_ALIGN_CENTER, "INSTRUCOES");
	}
    else al_draw_text(fonte_opcoes, al_map_rgb(255, 255, 255), 640 / 2, 480 / 2 + 40, ALLEGRO_ALIGN_CENTER, "INSTRUCOES");
    if (opcao_selecionada == RECORDES)
	{
        al_draw_text(fonte_opcoes, cor_selecionado, 640 / 2, 480 / 2 + 76, ALLEGRO_ALIGN_CENTER, "RECORDES");
	}
	else al_draw_text(fonte_opcoes, al_map_rgb(255, 255, 255), 640 / 2, 480 / 2 + 76, ALLEGRO_ALIGN_CENTER, "RECORDES");
	if (opcao_selecionada == SAIR)
	{
        al_draw_text(fonte_opcoes, cor_selecionado, 640 / 2, 480 / 2 + 112, ALLEGRO_ALIGN_CENTER, "SAIR");
	}
	else al_draw_text(fonte_opcoes, al_map_rgb(255, 255, 255), 640 / 2, 480 / 2 + 112, ALLEGRO_ALIGN_CENTER, "SAIR");
}

void menu(){
	inicializa_menu(); //Define algumas valores e carrega as fontes
	desenha_menu();//Chama Funcao q desenha o menu
	al_start_timer(timer);
	while (!fim)
	{

		ALLEGRO_EVENT evento;//cria struct do evento atual
		al_wait_for_event(fila_de_eventos, &evento);//espera evento acontecer

		//------EVENTOS E LÓGICA DO JOGO----------

		if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)//ve se um evento de DISPLAY foi feito(no caso, clicar no X da tela)
		{
			fim = true;
		}

		else if (evento.type == ALLEGRO_EVENT_KEY_UP)//ve se um evento de TECLADO foi feito(no caso, soltar a tecla)
		{
			if (evento.keyboard.keycode == ALLEGRO_KEY_ESCAPE)//se ESC for clicado, fecha o jogo
			{
				fim = true;
			}
		}

		else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)//ve se um evento de TECLADO foi feito(no caso, soltar a tecla)
		{

			switch (evento.keyboard.keycode)//caso CIMA E BAIXO sejam clicados, muda a cor da opcao no menu
			{
			case ALLEGRO_KEY_DOWN:
				if (opcao_selecionada < 3)
				{
					opcao_selecionada = opcao_selecionada + 1;
					al_clear_to_color(al_map_rgb(0, 0, 0));
					desenha_menu();//Chama Funcao q desenha o menu
				}
				break;
			case ALLEGRO_KEY_UP:
				if (opcao_selecionada > 0)
				{
					opcao_selecionada = opcao_selecionada - 1;
					al_clear_to_color(al_map_rgb(0, 0, 0));
					desenha_menu();//Chama Funcao q desenha o menu
				}
				break;
			}

			if ((evento.keyboard.keycode == ALLEGRO_KEY_ENTER || evento.keyboard.keycode == ALLEGRO_KEY_PAD_ENTER) && opcao_selecionada == 3)//ve se a opcao SAIR do menu foi selecionada pelos enteres(ou o normal ou o do num_pad) do teclado
			{
				fim = true;
			}

			else if ((evento.keyboard.keycode == ALLEGRO_KEY_ENTER || evento.keyboard.keycode == ALLEGRO_KEY_PAD_ENTER) && opcao_selecionada == 1)//ve se a opcao INSTRUCOES do menu foi selecionada pelos enteres(ou o normal ou o do num_pad) do teclado.
			{
				al_clear_to_color(al_map_rgb(0, 0, 0));
				//desenha_instrucoes(display);//nao sei oq fazer ainda pra ir pra tela de instrucoes
				desenha_menu();
			}

			else if ((evento.keyboard.keycode == ALLEGRO_KEY_ENTER || evento.keyboard.keycode == ALLEGRO_KEY_PAD_ENTER) && opcao_selecionada == 2)//ve se a opcao RECORDES do menu foi selecionada pelos enteres(ou o normal ou o do num_pad) do teclado
			{
				fim = true;
			}
			
			else if ((evento.keyboard.keycode == ALLEGRO_KEY_ENTER || evento.keyboard.keycode == ALLEGRO_KEY_PAD_ENTER) && opcao_selecionada == 0)//ve se a opcao NOVO JOGO do menu foi selecionada pelos enteres(ou o normal ou o do num_pad) do teclado.
			{
				printf("Novo Jogo\n");
				al_clear_to_color(al_map_rgb(0, 0, 0));
				novo_jogo();
			}
		}

		//------DESENHO MENU----------------------
		//al_draw_textf(fonte20,al_map_rgb(255,255,255), 0,0, NULL, "Quadros: %i", contador++);
		al_flip_display();//Flip na Tela
	}
}