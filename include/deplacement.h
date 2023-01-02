#pragma once

#include "joueur.h"
#include "section.h"
#include <ncurses.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// parametre la taille de la fenetre
#define LONGUEUR 25
#define LARGEUR 70
#define X 10
#define Y 10

enum direction {
  PAVE_HAUT = '8',
  PAVE_DROIT = '6',
  PAVE_BAS = '2',
  PAVE_GAUCHE = '4',
  PAVE_HAUT_DROIT = '9',
  PAVE_HAUT_GAUCHE = '7',
  PAVE_BAS_DROIT = '3',
  PAVE_BAS_GAUCHE = '1'
};

void initStructureFenetre();
WINDOW *creerFenetre(int longueur, int largeur, int x, int y);
void redessinerFenetre(WINDOW *fenetre);
bool deplacementValide(ptrSection **mat, int input, Joueur joueur);
void traiterDeplacement(WINDOW *fenetre, int input, ptrSection **mat,Joueur joueur);