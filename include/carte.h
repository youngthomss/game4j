#pragma once
#include "commons.h"
#include "joueur.h"
#include "section.h"

void afficherInstructions();
void afficherCarte(ptrSection **carte, int taille);
void afficher(ptrSection **carte, int taille, ptrJoueur j);
void clear();