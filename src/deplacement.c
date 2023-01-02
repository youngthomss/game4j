#include "deplacement.h"

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

bool deplacementValide(ptrSection **mat, int input, Joueur joueur) {
  // En fonction de la touche entrée par l'utilisateur,
  // on vérifie si le déplacement est valide, réalisable
  switch (input) {
  // Déplacement vers le haut :
  case PAVE_HAUT:
    if (mat[joueur.position.row - 1][joueur.position.col]->terrain != -1) {
      return true;
    }
    break;
  // Déplacement à droite :
  case PAVE_DROIT:
    if (mat[joueur.position.row][joueur.position.col + 1]->terrain != -1) {
      return true;
    }
    break;
  // Déplacement vers le bas :
  case PAVE_BAS:
    if (mat[joueur.position.row + 1][joueur.position.col]->terrain != -1) {
      return true;
    }
    break;
  // Déplacement à gauche :
  case PAVE_GAUCHE:
    if (mat[joueur.position.row][joueur.position.col - 1]->terrain != -1) {
      return true;
    }
    break;
  // Déplacement en haut à droite :
  case PAVE_HAUT_DROIT:
    if (mat[joueur.position.row - 1][joueur.position.col + 1]->terrain != -1) {
      return true;
    }
    break;
  // Déplacement en haut à gauche :
  case PAVE_HAUT_GAUCHE:
    if (mat[joueur.position.row - 1][joueur.position.col - 1]->terrain != -1) {
      return true;
    }
    break;
  // Déplacement en bas à droite :
  case PAVE_BAS_DROIT:
    if (mat[joueur.position.row + 1][joueur.position.col + 1]->terrain != -1) {
      return true;
    }
    break;
  // Déplacement en bas à gauche :
  case PAVE_BAS_GAUCHE:
    if (mat[joueur.position.row + 1][joueur.position.col - 1]->terrain != -1) {
      return true;
    }
    break;
  }
  return false;
}

void traiterDeplacement(WINDOW *fenetre, int input, ptrSection **mat,
                        Joueur joueur) {
  switch (input) {

  case PAVE_HAUT:
    if (deplacementValide(mat, input, joueur)) {
      joueur.position.row -= 1;
      printf("%d", joueur.position.row);
      redessinerFenetre(fenetre);
      mvwprintw(fenetre, 10, 25, "Tu te déplaces en haut");
      wrefresh(fenetre);
    };
    break;

  case PAVE_DROIT:
    if (deplacementValide(mat, input, joueur)) {
      joueur.position.col += 1;
      printf("%d", joueur.position.col);
      redessinerFenetre(fenetre);
      mvwprintw(fenetre, 10, 25, "Tu te déplaces à droite");
      wrefresh(fenetre);
    };
    break;

  case PAVE_BAS:
    if (deplacementValide(mat, input, joueur)) {
      joueur.position.row += 1;
      printf("%d", joueur.position.row);
      redessinerFenetre(fenetre);
      mvwprintw(fenetre, 10, 25, "Tu te déplaces en bas");
      wrefresh(fenetre);
    };
    break;

  case PAVE_GAUCHE:
    if (deplacementValide(mat, input, joueur)) {
      joueur.position.col -= 1;
      printf("%d", joueur.position.col);
      redessinerFenetre(fenetre);
      mvwprintw(fenetre, 10, 25, "Tu te déplaces à gauche");
      wrefresh(fenetre);
    };
    break;

  case PAVE_HAUT_DROIT:
    if (deplacementValide(mat, input, joueur)) {
      joueur.position.col += 1;
      joueur.position.row -= 1;
      printf("row = %d and col = %d", joueur.position.col, joueur.position.col);
      redessinerFenetre(fenetre);
      mvwprintw(fenetre, 10, 25, "Tu te déplaces en haut à droite");
      wrefresh(fenetre);
    };
    break;

  case PAVE_HAUT_GAUCHE:
    if (deplacementValide(mat, input, joueur)) {
      joueur.position.col -= 1;
      joueur.position.row -= 1;
      printf("row = %d and col = %d", joueur.position.col, joueur.position.col);
      redessinerFenetre(fenetre);
      mvwprintw(fenetre, 10, 25, "Tu te déplaces en haut à gauche");
      wrefresh(fenetre);
    };
    break;

  case PAVE_BAS_DROIT:
    if (deplacementValide(mat, input, joueur)) {
      joueur.position.col += 1;
      joueur.position.row += 1;
      printf("row = %d and col = %d", joueur.position.col, joueur.position.col);
      redessinerFenetre(fenetre);
      mvwprintw(fenetre, 10, 25, "Tu te déplaces en bas à droite");
      wrefresh(fenetre);
    };
    break;

  case PAVE_BAS_GAUCHE:
    if (deplacementValide(mat, input, joueur)) {
      joueur.position.col -= 1;
      joueur.position.row += 1;
      printf("row = %d and col = %d", joueur.position.col, joueur.position.col);
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
