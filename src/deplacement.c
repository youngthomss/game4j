#include "deplacement.h"

bool deplacementValide(ptrSection **carte, int deplacementSuivantRow, int deplacementSuivantCol, int taille) {
  if (deplacementSuivantRow < taille && deplacementSuivantCol < taille && deplacementSuivantRow >= 0 && deplacementSuivantCol >= 0) {
    if (carte[deplacementSuivantRow][deplacementSuivantCol]->terrain != -1) {
      return true;
    }
  }
  return false;
}

void deplacerJoueur(ptrSection **carte, ptrJoueur joueur, int ancienRow, int ancienCol) {
  carte[ancienRow][ancienCol]->terrain = 0;
  if (carte[joueur->position->row][joueur->position->col]->terrain == 1) {
    joueur->energie += 2;
    printf("Bonus : +1 énergie !\n");
  }

  carte[joueur->position->row][joueur->position->col]->terrain = 2;
  joueur->energie -= 1;
}

void traiterDeplacement(ptrSection **carte, int deplacement, ptrJoueur joueur, int taille) {
  int ancienRow = joueur->position->row;
  int ancienCol = joueur->position->col;
  int deplacementSuivantRow;
  int deplacementSuivantCol;

  switch (deplacement) {

  case PAVE_HAUT:
    deplacementSuivantCol = joueur->position->col;
    deplacementSuivantRow = joueur->position->row - 1;
    if (deplacementValide(carte, deplacementSuivantRow, deplacementSuivantCol, taille)) {
      joueur->position->row -= 1;
      deplacerJoueur(carte, joueur, ancienRow, ancienCol);
    }
    break;

  case PAVE_DROIT:
    deplacementSuivantCol = joueur->position->col + 1;
    deplacementSuivantRow = joueur->position->row;
    if (deplacementValide(carte, deplacementSuivantRow, deplacementSuivantCol, taille)) {
      joueur->position->col += 1;
      deplacerJoueur(carte, joueur, ancienRow, ancienCol);
    }
    break;

  case PAVE_BAS:
    deplacementSuivantCol = joueur->position->col;
    deplacementSuivantRow = joueur->position->row + 1;
    if (deplacementValide(carte, deplacementSuivantRow, deplacementSuivantCol, taille)) {
      joueur->position->row += 1;
      deplacerJoueur(carte, joueur, ancienRow, ancienCol);
    }
    break;

  case PAVE_GAUCHE:
    deplacementSuivantCol = joueur->position->col -1;
    deplacementSuivantRow = joueur->position->row;
    if (deplacementValide(carte, deplacementSuivantRow, deplacementSuivantCol, taille)) {
      joueur->position->col -= 1;
      deplacerJoueur(carte, joueur, ancienRow, ancienCol);
    }
    break;

  case PAVE_HAUT_DROIT:
    deplacementSuivantCol = joueur->position->col + 1;
    deplacementSuivantRow = joueur->position->row - 1;
    if (deplacementValide(carte, deplacementSuivantRow, deplacementSuivantCol, taille)) {
      joueur->position->col += 1;
      joueur->position->row -= 1;      
      deplacerJoueur(carte, joueur, ancienRow, ancienCol);
    }
    break;

  case PAVE_HAUT_GAUCHE:
    deplacementSuivantCol = joueur->position->col - 1;
    deplacementSuivantRow = joueur->position->row - 1;
    if (deplacementValide(carte, deplacementSuivantRow, deplacementSuivantCol, taille)) {
      joueur->position->col -= 1;
      joueur->position->row -= 1;      
      deplacerJoueur(carte, joueur, ancienRow, ancienCol);
    }
    break;

  case PAVE_BAS_DROIT:
    deplacementSuivantCol = joueur->position->col + 1;
    deplacementSuivantRow = joueur->position->row + 1;
    if (deplacementValide(carte, deplacementSuivantRow, deplacementSuivantCol, taille)) {
      joueur->position->col += 1;
      joueur->position->row += 1;      
      deplacerJoueur(carte, joueur, ancienRow, ancienCol);
    }
    break;

  case PAVE_BAS_GAUCHE:
    deplacementSuivantCol = joueur->position->col - 1;
    deplacementSuivantRow = joueur->position->row + 1;
    if (deplacementValide(carte, deplacementSuivantRow, deplacementSuivantCol, taille)) {
      joueur->position->col -= 1;
      joueur->position->row += 1;      
      deplacerJoueur(carte, joueur, ancienRow, ancienCol);
    }
    break;

  default:
    break;
  }
};
