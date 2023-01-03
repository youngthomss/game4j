#pragma once
#include "commons.h"
#include "section.h"
#include "joueur.h"

void afficherInstructions();
void afficherCarte(ptrSection **carte, int taille);
void afficher(ptrSection **carte, int taille, ptrJoueur j);
void clear();