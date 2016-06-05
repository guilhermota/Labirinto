#include <stdlib.h>
#include <stdio.h>

#include "allegro5/allegro.h"
#include "allegro5/allegro_font.h"
#include "allegro5/allegro_ttf.h"

//--------VARIAVEIS-----------------
int Largura_t;
int Altura_t;
int FPS;

bool fim;

//long int contador = 0;//pra medir os quadros por segundo

//--------INICIALIZAÇÂO DA FILA DE EVENTOS----------
//-------------E OUTROS PONTEIROS-------------------
ALLEGRO_EVENT_QUEUE *fila_de_eventos;
ALLEGRO_TIMER *timer;
//ALLEGRO_FONT *fonte20 = NULL;//usado pra medir os quadros por segunda na tela
