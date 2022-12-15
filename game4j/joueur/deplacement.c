#include "deplacement.h"
#include "joueur.h"

#include <ncurses.h>

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

void traiterDeplacement(WINDOW *fenetre, int input) {
  switch (input) {

  case PAVE_HAUT:
    redessinerFenetre(fenetre);
    mvwprintw(fenetre, 10, 25, "Tu te déplaces en haut");
    wrefresh(fenetre);
    break;

  case PAVE_DROIT:
    redessinerFenetre(fenetre);
    mvwprintw(fenetre, 10, 25, "Tu te déplaces à droite");
    wrefresh(fenetre);
    break;

  case PAVE_BAS:
    redessinerFenetre(fenetre);
    mvwprintw(fenetre, 10, 25, "Tu te déplaces en bas");
    wrefresh(fenetre);
    break;

  case PAVE_GAUCHE:
    redessinerFenetre(fenetre);
    mvwprintw(fenetre, 10, 25, "Tu te déplaces à gauche");
    wrefresh(fenetre);
    break;

case PAVE_HAUT_DROIT:
    redessinerFenetre(fenetre);
    mvwprintw(fenetre, 10, 25, "Tu te déplaces en haut à droite");
    wrefresh(fenetre);
    break;

    case PAVE_HAUT_GAUCHE:
    redessinerFenetre(fenetre);
    mvwprintw(fenetre, 10, 25, "Tu te déplaces en haut à gauche");
    wrefresh(fenetre);
    break;

    case PAVE_BAS_DROIT:
    redessinerFenetre(fenetre);
    mvwprintw(fenetre, 10, 25, "Tu te déplaces en bas à droite ");
    wrefresh(fenetre);
    break;

    case PAVE_BAS_GAUCHE:
    redessinerFenetre(fenetre);
    mvwprintw(fenetre, 10, 25, "Tu te déplaces en bas à gauche");
    wrefresh(fenetre);
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
