#include "deplacement.h"

bool deplacementValide(ptrSection **carte, int deplacementSuivantRow, int deplacementSuivantCol, int taille) {
  if (deplacementSuivantRow < taille && deplacementSuivantCol < taille && deplacementSuivantRow >= 0 && deplacementSuivantCol >= 0) {
      return (carte[deplacementSuivantRow][deplacementSuivantCol]->terrain != -1);
    }
  return false;
}

void deplacerJoueur(ptrSection **carte, ptrJoueur joueur, int ancienRow, int ancienCol) {
  carte[ancienRow][ancienCol]->terrain = -2;
  if (carte[joueur->position->row][joueur->position->col]->terrain == 1) {
    joueur->energie += 2;
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

  case HAUTE:
    deplacementSuivantCol = joueur->position->col;
    deplacementSuivantRow = joueur->position->row - 1;
    if (deplacementValide(carte, deplacementSuivantRow, deplacementSuivantCol, taille)) {
      joueur->position->row -= 1;
      deplacerJoueur(carte, joueur, ancienRow, ancienCol);
    }
    break;

  case DROITE:
    deplacementSuivantCol = joueur->position->col + 1;
    deplacementSuivantRow = joueur->position->row;
    if (deplacementValide(carte, deplacementSuivantRow, deplacementSuivantCol, taille)) {
      joueur->position->col += 1;
      deplacerJoueur(carte, joueur, ancienRow, ancienCol);
    }
    break;

  case BASSE:
    deplacementSuivantCol = joueur->position->col;
    deplacementSuivantRow = joueur->position->row + 1;
    if (deplacementValide(carte, deplacementSuivantRow, deplacementSuivantCol, taille)) {
      joueur->position->row += 1;
      deplacerJoueur(carte, joueur, ancienRow, ancienCol);
    }
    break;

  case GAUCHE:
    deplacementSuivantCol = joueur->position->col -1;
    deplacementSuivantRow = joueur->position->row;
    if (deplacementValide(carte, deplacementSuivantRow, deplacementSuivantCol, taille)) {
      joueur->position->col -= 1;
      deplacerJoueur(carte, joueur, ancienRow, ancienCol);
    }
    break;

  case HAUTE_DROITE:
    deplacementSuivantCol = joueur->position->col + 1;
    deplacementSuivantRow = joueur->position->row - 1;
    if (deplacementValide(carte, deplacementSuivantRow, deplacementSuivantCol, taille)) {
      joueur->position->col += 1;
      joueur->position->row -= 1;      
      deplacerJoueur(carte, joueur, ancienRow, ancienCol);
    }
    break;

  case HAUTE_GAUCHE:
    deplacementSuivantCol = joueur->position->col - 1;
    deplacementSuivantRow = joueur->position->row - 1;
    if (deplacementValide(carte, deplacementSuivantRow, deplacementSuivantCol, taille)) {
      joueur->position->col -= 1;
      joueur->position->row -= 1;      
      deplacerJoueur(carte, joueur, ancienRow, ancienCol);
    }
    break;

  case BASSE_DROITE:
    deplacementSuivantCol = joueur->position->col + 1;
    deplacementSuivantRow = joueur->position->row + 1;
    if (deplacementValide(carte, deplacementSuivantRow, deplacementSuivantCol, taille)) {
      joueur->position->col += 1;
      joueur->position->row += 1;      
      deplacerJoueur(carte, joueur, ancienRow, ancienCol);
    }
    break;

  case BASSE_GAUCHE:
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
