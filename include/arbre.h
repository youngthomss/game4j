#pragma once
#include "commons.h"
#include "generation.h"
#include "section.h"

int **genererMatriceAdjacente(ptrSection **matrice, int taille);
void creerDistance(ptrSection case1, ptrSection case2, int **mat, int taille);
void afficherMatriceAdjacente(int **mat, int taille);
int convertCaseToInt(int x, int y, int taille);
int **genererMatriceVide(int taille);
