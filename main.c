#include "main.h"
#include "menu.h"

int main(){

//--------INICIALIZAÇÂO DO DISPLAY-------------------
	ALLEGRO_DISPLAY *display = NULL;
	if(!al_init())
    {
        fprintf(stderr, "Problema ao Inicializar!\n");
		return -1;
    }


	Largura_t = 640;
	Altura_t = 480;
	FPS = 60;
	fim = false;

	//long int contador = 0;//pra medir os quadros por segundo

    al_set_new_display_flags(ALLEGRO_RESIZABLE);
	display = al_create_display(Largura_t, Altura_t);
	if (!display) {
		fprintf(stderr, "failed to create display!\n");
		return -1;
	}

	//--------INICIALIZAÇÂO DA FILA DE EVENTOS----------
	//-------------E OUTROS PONTEIROS-------------------
	fila_de_eventos = NULL;
	timer = NULL;
	//ALLEGRO_FONT *fonte20 = NULL;//usado pra medir os quadros por segunda na tela


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
	menu();

//--------FINALIZAÇÔES DO PROGRAMA(Desaloca Memoria)------------------
	al_destroy_display(display);
	al_destroy_event_queue(fila_de_eventos);
	al_destroy_timer(timer);
	//al_destroy_font(fonte20);//usado pra escrever os quadros por segundo na tela

	return 0;
}


