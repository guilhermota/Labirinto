#include <stdio.h>
#include <allegro5/allegro.h>

#include "menu.h"


int main(int argc, char **argv){

	al_init();
	al_init_font_addon();
	al_init_ttf_addon();
	al_init_primitives_addon();

	ALLEGRO_DISPLAY *display = NULL;
	
	display = al_create_display(640, 480);
	if (!display) {
		fprintf(stderr, "failed to create display!\n");
		return -1;
	}

	al_clear_to_color(al_map_rgb(0, 0, 0));
	
	desenha_menu(display);

	al_flip_display();

	al_rest(10.0);

	al_destroy_display(display);

	return 0;
}