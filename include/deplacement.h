#pragma once

#include "joueur.h"
#include "section.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


enum direction {
  PAVE_HAUT = 8,
  PAVE_DROIT = 6,
  PAVE_BAS = 2,
  PAVE_GAUCHE = 4,
  PAVE_HAUT_DROIT = 9,
  PAVE_HAUT_GAUCHE = 7,
  PAVE_BAS_DROIT = 3,
  PAVE_BAS_GAUCHE = 1
};


bool deplacementValide(ptrSection **carte, int deplacementSuivantRow, int deplacementSuivantCol, int taille);
void traiterDeplacement(ptrSection **carte, int deplacement, ptrJoueur joueur, int taille);
void deplacerJoueur(ptrSection **carte, ptrJoueur joueur, int ancienRow, int ancienCol);