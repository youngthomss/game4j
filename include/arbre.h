#pragma once
#include "commons.h"
#include "generation.h"
#include "section.h"

int **construireMatrice(ptrSection **matrice, int taille);
void creerDistance(ptrSection case1, ptrSection case2, int **mat, int taille);
void afficherMatriceV2(int **mat, int taille);
int convertCaseToInt(int x, int y, int taille);
int **genererMatrice(int taille);
