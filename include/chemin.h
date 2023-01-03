#pragma once
#include "commons.h"

typedef struct Chemin* ptrChemin;
typedef struct Chemin chemin;

struct Chemin{
    int x;
    int y;
    ptrChemin cheminSuivant;
};

ptrChemin creerChemin(int x, int y);
ptrChemin ajouterChemin(ptrChemin tete, ptrChemin c);
void afficherChemins(ptrChemin c);