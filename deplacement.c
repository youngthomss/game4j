#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "/include/joueur.h"
#include "/include/deplacement.h"

enum direction {
  HAUT = 1,
  DROITE = 2,
  BAS = 3,
  GAUCHE = 3,
  PAVE_HAUT = '8',
  PAVE_DROIT = '6',
  PAVE_BAS = '2',
  PAVE_GAUCHE = '4',
  PAVE_HAUT_DROIT = '9',
  PAVE_HAUT_GAUCHE = '7',
  PAVE_BAS_DROIT = '3',
  PAVE_BAS_GAUCHE = '1'
};
// parametre la taille de la fenetre
#define LONGUEUR 25
#define LARGEUR 70
#define X 10
#define Y 10


void initStructureFenetre() {
  initscr(); // Initialise la structure WINDOW et autres paramètres
  noecho();
  curs_set(0);
}

WINDOW *creerFenetre(int longueur, int largeur, int x, int y) {
  // Creer une fenetre pour l'input
  WINDOW *fenetre = newwin(longueur, largeur, x, y);
  box(fenetre, 0, 0);
  refresh();
  wrefresh(fenetre);

  return fenetre;
}

void redessinerFenetre(WINDOW *fenetre) {
  werase(fenetre);
  box(fenetre, 0, 0); 
  wrefresh(fenetre);
}

bool deplacement_valide(ptrSection** mat, int input, Joueur joueur) {
    // En fonction de la touche entrée par l'utilisateur,
    // on vérifie si le déplacement est valide, réalisable
    switch (input) {
        // Déplacement vers le haut :
        case PAVE_HAUT:
            if (mat[joueur.row -1][joueur.col] != -1) {
                return true;
            }
            break;
        // Déplacement à droite :
        case PAVE_DROIT:
            if (mat[joueur.row][joueur.col +1] != -1) {
                return true;
            }
            break;
        // Déplacement vers le bas :
        case PAVE_BAS:
            if (mat[joueur.row +1][joueur.col] != -1) {
                return true;
            }
            break;
        // Déplacement à gauche :
        case PAVE_GAUCHE:
            if (mat[joueur.row][joueur.col -1] != -1) {
                return true;
            }
            break;
        // Déplacement en haut à droite :
        case PAVE_HAUT_DROIT:
            if (mat[joueur.row -1][joueur.col +1] != -1) {
                return true;
            }
            break;
        // Déplacement en haut à gauche :
        case PAVE_HAUT_GAUCHE:
            if (mat[joueur.row -1][joueur.col -1] != -1) {
                return true;
            }
            break;
        // Déplacement en bas à droite :
        case PAVE_BAS_DROIT:
            if (mat[joueur.row +1][joueur.col +1] != -1) {
                return true;
            }
            break;
        // Déplacement en bas à gauche :
        case PAVE_BAS_GAUCHE:
            if (mat[joueur.row +1][joueur.col -1] != -1) {
                return true;
            }
            break;
    }
    return false;
}

void traiterDeplacement(WINDOW *fenetre, int input, ptrSection** mat, Joueur joueur) {
  switch (input) {

  case PAVE_HAUT:
    if(deplacementValide(mat, input, joueur)){
      joueur.row -= 1;
      printf("%d", joueur.row)
      redessinerFenetre(fenetre);
      mvwprintw(fenetre, 10, 25, "Tu te déplaces en haut");
      wrefresh(fenetre);
    };
    break;

  case PAVE_DROIT:
    if(deplacementValide(mat, input, joueur)){
      joueur.col += 1;
      printf("%d", joueur.col)
      redessinerFenetre(fenetre);
      mvwprintw(fenetre, 10, 25, "Tu te déplaces à droite");
      wrefresh(fenetre);
    };
    break;

  case PAVE_BAS:
    if(deplacementValide(mat, input, joueur)){
      joueur.row += 1;
      printf("%d", joueur.row)
      redessinerFenetre(fenetre);
      mvwprintw(fenetre, 10, 25, "Tu te déplaces en bas");
      wrefresh(fenetre);
    };
    break;

  case PAVE_GAUCHE:
    if(deplacementValide(mat, input, joueur)){
      joueur.col -= 1;
      printf("%d", joueur.col)
      redessinerFenetre(fenetre);
      mvwprintw(fenetre, 10, 25, "Tu te déplaces à gauche");
      wrefresh(fenetre);
    };
    break;

case PAVE_HAUT_DROIT:
    if(deplacementValide(mat, input, joueur)){
      joueur.col += 1;
      joueur.row -= 1;
      printf("row = %d and col = %d", joueur.col, joueur.col)
      redessinerFenetre(fenetre);
      mvwprintw(fenetre, 10, 25, "Tu te déplaces en haut à droite");
      wrefresh(fenetre);
    };
    break;

  case PAVE_HAUT_GAUCHE:
    if(deplacementValide(mat, input, joueur)){
      joueur.col -= 1;
      joueur.row -= 1;
      printf("row = %d and col = %d", joueur.col, joueur.col)
      redessinerFenetre(fenetre);
      mvwprintw(fenetre, 10, 25, "Tu te déplaces en haut à gauche");
      wrefresh(fenetre);
    };
    break;

  case PAVE_BAS_DROIT:
    if(deplacementValide(mat, input, joueur)){
      joueur.col += 1;
      joueur.row += 1;
      printf("row = %d and col = %d", joueur.col, joueur.col)
      redessinerFenetre(fenetre);
      mvwprintw(fenetre, 10, 25, "Tu te déplaces en bas à droite");
      wrefresh(fenetre);
    };
    break;

  case PAVE_BAS_GAUCHE:
    if(deplacementValide(mat, input, joueur)){
      joueur.col -= 1;
      joueur.row += 1;
      printf("row = %d and col = %d", joueur.col, joueur.col)
      redessinerFenetre(fenetre);
      mvwprintw(fenetre, 10, 25, "Tu te déplaces en bas à gauche");
      wrefresh(fenetre);
    };
    break;
  break;

  default:
    redessinerFenetre(fenetre);
    mvwprintw(fenetre, 10, 15, "Erreur, choisissez une bonne direction");
    wrefresh(fenetre);
    break;
  }
};

int main() {

  initStructureFenetre();
  WINDOW *fenetre = creerFenetre(LONGUEUR, LARGEUR, X, Y);
  keypad(fenetre, TRUE);   
  // nodelay(fenetre, TRUE); //pour eviter de bloquer la fenetre en attendant qu'une touche sois entrée

  int i = 0;
  while (i == 0) {
    int input = wgetch(fenetre);
    traiterDeplacement(fenetre, input);
  }

  getch();
  endwin();
  
  return 0;
}
