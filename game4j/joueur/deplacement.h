#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

enum DIRECTION {
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
void traiterDeplacement(WINDOW *fenetre, int input);
