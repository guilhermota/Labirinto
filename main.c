#include <stdlib.h>
#include <stdio.h>

#include "allegro5/allegro.h"
#include "menu.h"

int main(int argc, char **argv){

    const int Largura_t = 640;
    const int Altura_t = 480;

    //Inicialização dos Addons(modulos)
	al_init();
	al_init_font_addon();
	al_init_ttf_addon();
	al_init_primitives_addon();

    //Inicializa o Display
	ALLEGRO_DISPLAY *display = NULL;
	display = al_create_display(Largura_t, Altura_t);
	if (!display) {
		fprintf(stderr, "failed to create display!\n");
		return -1;
	}
    //Inicializa o Display com fundo Preto
	al_clear_to_color(al_map_rgb(0, 0, 0));
    //Chama Funcao q desenha o menu
	desenha_menu(display);
    //Flip na Tela
	al_flip_display();

	al_rest(10.0);

    //Desaloca Memoria
	al_destroy_display(display);

	return 0;
}
