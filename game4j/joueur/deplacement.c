#include "deplacement.h"
#include <ncurses.h>
enum direction {
  HAUT = 1,
  DROITE = 2,
  BAS = 3,
  GAUCHE = 3,
  PAVE_HAUT = '8',
  PAVE_DROIT = '6',
  PAVE_BAS = '2',
  PAVE_GAUCHE = '4'
};
// parametre la taille de la fenetre
#define LONGUEUR 25
#define LARGEUR 70
#define X 10
#define Y 10

// En incluant la bibliothèque ncurses.h, nous n'avons plus besoin d'inclure la
// bibliothèque stdio.h car celle ci est inclue implicitement dans ncurses.h

// Lors de la compilation avec gcc, il faut spécifier que vus utilisez la
// bibliothèque Ncurses et pour cela il vous faut rajouter l'option lncurses.
// Exemple gcc -lncurses -o HelloWorld HelloWorld.c

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
  box(fenetre, 0, 0); // recree la partie de la bordure droite supp
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
  keypad(fenetre, TRUE); /* pour récupérer les événements du clavier */
  // nodelay(fenetre, TRUE); //pour eviter de bloquer la fenetre en attendant
  // qu'une touche sois entrée

  int i = 0;
  while (i == 0) {
    int input = wgetch(fenetre);
    traiterDeplacement(fenetre, input);
  }

  getch();
  endwin();
  
  return 0;
}
