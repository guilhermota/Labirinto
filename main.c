#include <stdlib.h>
#include <stdio.h>

#include "allegro5/allegro.h"
#include "allegro5/allegro_font.h"
#include "allegro5/allegro_ttf.h"
#include "menu.h"

int main(){

//--------VARIAVEIS-----------------
    const int Largura_t = 640;
    const int Altura_t = 480;
    const int FPS = 60;

    bool fim = false;

    //long int contador = 0;//pra medir os quadros por segundo


//--------INICIALIZAÇÂO DA FILA DE EVENTOS----------
//-------------E OUTROS PONTEIROS-------------------
    ALLEGRO_EVENT_QUEUE *fila_de_eventos = NULL;
    ALLEGRO_TIMER *timer = NULL;
    //ALLEGRO_FONT *fonte20 = NULL;//usado pra medir os quadros por segunda na tela

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

//--------INICIALIZAÇÂO DOS ADDONS(modulos)-----------
	al_init_font_addon();
	al_init_ttf_addon();
	al_init_primitives_addon();
	al_install_keyboard();
	timer = al_create_timer((double) 1.0 / FPS);//vai regular os quadros por segundo

//--------CRIAÇÂO DA FILA DE EVENTOS------------------
	fila_de_eventos = al_create_event_queue();

//--------REGISTRO DE SOURCES(fontes de interrupcoes que vao pra fila de eventos)---------------
	al_register_event_source(fila_de_eventos, al_get_keyboard_event_source());
	al_register_event_source(fila_de_eventos, al_get_display_event_source(display));
	al_register_event_source(fila_de_eventos, al_get_timer_event_source(timer));

	//fonte20 = al_load_ttf_font("C:/Labirinto/fontes/arial.ttf", 20, 0);//usado pra escrever os quadros por segundo na tela

//--------LOOP INFINITO------------------
    desenha_menu(display);//Chama Funcao q desenha o menu
    al_start_timer(timer);
	while(!fim)
    {

        ALLEGRO_EVENT evento;//cria struct do evento atual
        al_wait_for_event(fila_de_eventos, &evento);//espera evento acontecer

        //------EVENTOS E LÓGICA DO JOGO----------

        if(evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)//ve se um evento de DISPLAY foi feito(no caso, clicar no X da tela)
        {
            fim = true;
        }

        else if(evento.type == ALLEGRO_EVENT_KEY_UP)//ve se um evento de TECLADO foi feito(no caso, soltar a tecla)
        {
            if(evento.keyboard.keycode == ALLEGRO_KEY_ESCAPE)//se ESC for clicado, fecha o jogo
            {
                fim = true;
            }
        }

        else if(evento.type == ALLEGRO_EVENT_KEY_DOWN)//ve se um evento de TECLADO foi feito(no caso, soltar a tecla)
        {

            switch(evento.keyboard.keycode)//caso CIMA E BAIXO sejam clicados, muda a cor da opcao no menu
            {
                case ALLEGRO_KEY_DOWN:
                if(opcao_selecionada < 3)
                {
                    opcao_selecionada = opcao_selecionada + 1;
                    al_clear_to_color(al_map_rgb(0,0,0));
                    desenha_menu(display);//Chama Funcao q desenha o menu
                }
                break;
                case ALLEGRO_KEY_UP:
                if(opcao_selecionada > 0)
                {
                    opcao_selecionada = opcao_selecionada - 1;
                    al_clear_to_color(al_map_rgb(0,0,0));
                    desenha_menu(display);//Chama Funcao q desenha o menu
                }
                break;
            }

            if((evento.keyboard.keycode == ALLEGRO_KEY_ENTER || evento.keyboard.keycode == ALLEGRO_KEY_PAD_ENTER) && opcao_selecionada == 3)//ve se a opcao SAIR do menu foi selecionada pelos enteres(ou o normal ou o do num_pad) do teclado
            {
                fim = true;
            }

            else if((evento.keyboard.keycode == ALLEGRO_KEY_ENTER || evento.keyboard.keycode == ALLEGRO_KEY_PAD_ENTER) && opcao_selecionada == 1)//ve se a opcao INSTRUCOES do menu foi selecionada pelos enteres(ou o normal ou o do num_pad) do teclado.
            {
                al_clear_to_color(al_map_rgb(0,0,0));
                //desenha_instrucoes(display);//nao sei oq fazer ainda pra ir pra tela de instrucoes
                desenha_menu(display);
            }

            else if((evento.keyboard.keycode == ALLEGRO_KEY_ENTER || evento.keyboard.keycode == ALLEGRO_KEY_PAD_ENTER) && opcao_selecionada == 2)//ve se a opcao RECORDES do menu foi selecionada pelos enteres(ou o normal ou o do num_pad) do teclado
            {
                fim = true;
            }
        }

        //------DESENHO MENU----------------------
        //al_draw_textf(fonte20,al_map_rgb(255,255,255), 0,0, NULL, "Quadros: %i", contador++);
        al_flip_display();//Flip na Tela
    }

	//al_rest(10.0);(nao precisa mais disso)

//--------FINALIZAÇÔES DO PROGRAMA(Desaloca Memoria)------------------
	al_destroy_display(display);
	al_destroy_event_queue(fila_de_eventos);
	al_destroy_timer(timer);
	//al_destroy_font(fonte20);//usado pra escrever os quadros por segundo na tela

	return 0;
}


