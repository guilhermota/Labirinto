#include <stdlib.h>
#include <stdio.h>

#include "allegro5/allegro.h"
#include "menu.h"

int main(){

//--------VARIAVEIS-----------------
    const int Largura_t = 640;
    const int Altura_t = 480;
    bool fim = false;

    //int pos_x = 100;//posicao em X do jogador
    //int pos_y = 100;//posicao em Y do jogador

//--------INICIALIZAÇÂO DA FILA DE EVENTOS----------
    ALLEGRO_EVENT_QUEUE *fila_de_eventos;

//--------INICIALIZAÇÂO DO DISPLAY-------------------
	ALLEGRO_DISPLAY *display = NULL;
	if(!al_init())
    {
        fprintf(stderr, "Problema ao Inicializar!\n");
		return -1;
    }
    al_set_new_display_flags(ALLEGRO_RESIZABLE);
	display = al_create_display(Largura_t, Altura_t);
	if (!display) {
		fprintf(stderr, "failed to create display!\n");
		return -1;
	}
    //Inicializa o Display com fundo Preto
	al_clear_to_color(al_map_rgb(0, 0, 0));

//--------INICIALIZAÇÂO DOS ADDONS(modulos)-----------
	al_init_font_addon();
	al_init_ttf_addon();
	al_init_primitives_addon();
	al_install_keyboard();

//--------CRIAÇÂO DA FILA DE EVENTOS------------------
	fila_de_eventos = al_create_event_queue();

//--------REGISTRO DE SOURCES(fontes de interrupcoes que vao pra fila de eventos)---------------
	al_register_event_source(fila_de_eventos, al_get_keyboard_event_source());
	al_register_event_source(fila_de_eventos, al_get_display_event_source(display));

//--------LOOP INFINITO------------------
	while(!fim)
    {
        ALLEGRO_EVENT evento;//cria struct do evento atual
        al_wait_for_event(fila_de_eventos, &evento);//espera evento acontecer

        //------EVENTOS E LÓGICA DO JOGO----------
        if(evento.type == ALLEGRO_EVENT_KEY_UP)//ve se um evento de TECLADO foi feito(no caso, soltar a tecla)
        {
            if(evento.keyboard.keycode == ALLEGRO_KEY_ESCAPE)//se ESC for clicado, fecha o jogo
            {
                fim = true;
            }

            switch(evento.keyboard.keycode)//caso CIMA E BAIXO sejam clicados, muda a cor da opcao no menu
            {
                case ALLEGRO_KEY_DOWN:
                if(opcao_selecionada < 3)
                {
                    opcao_selecionada = opcao_selecionada + 1;
                }
                break;
                case ALLEGRO_KEY_UP:
                if(opcao_selecionada > 0)
                {
                    opcao_selecionada = opcao_selecionada - 1;
                }
                break;
            }

            if((evento.keyboard.keycode == ALLEGRO_KEY_ENTER || evento.keyboard.keycode == ALLEGRO_KEY_PAD_ENTER) && opcao_selecionada == 3)//ve se a opcao SAIR do menu foi selecionada pelos enteres(ou o normal ou o do num_pad) do teclado
            {
                fim = true;
            }
        }

        else if(evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)//ve se um evento de DISPLAY foi feito(no caso, clicar no X da tela)
        {
            fim = true;
        }

        //------DESENHO MENU----------------------
        desenha_menu(display);//Chama Funcao q desenha o menu
        al_flip_display();//Flip na Tela


    }

	//al_rest(10.0);(nao precisa mais disso)

//--------FINALIZAÇÔES DO PROGRAMA(Desaloca Memoria)------------------
	al_destroy_display(display);
	al_destroy_event_queue(fila_de_eventos);

	return 0;
}
