#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>  
#include "position.h"
#include "generation.h"


typedef struct Joueur {
    Position position;
    int Energie;

} Joueur;

void afficheGrilleNcurses(WINDOW* fenetre, ptrSection** mat, int taille);
