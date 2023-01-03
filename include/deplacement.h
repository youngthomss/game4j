#pragma once
#include "commons.h"
#include "joueur.h"
#include "section.h"


enum direction {
  HAUTE = 8,
  DROITE = 6,
  BASSE = 2,
  GAUCHE = 4,
  HAUTE_DROITE = 9,
  HAUTE_GAUCHE = 7,
  BASSE_DROITE = 3,
  BASSE_GAUCHE = 1
};


bool deplacementValide(ptrSection **carte, int deplacementSuivantRow, int deplacementSuivantCol, int taille);
void traiterDeplacement(ptrSection **carte, int deplacement, ptrJoueur joueur, int taille);
void deplacerJoueur(ptrSection **carte, ptrJoueur joueur, int ancienRow, int ancienCol);