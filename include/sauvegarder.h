#pragma once
#include "commons.h"
#include "generation.h"
#include "section.h"
#include "arbre.h"
#define taillechemin 100
#define taillenom 30
typedef struct Partie partie;
typedef struct Partie* ptrPartie;
typedef struct Data data;
typedef struct Data* ptrData;

struct Partie{
    int id; 
    char chemin[taillechemin];
    char nomPartie[taillenom];
};

void NomSauvegarde(char* chemin);
void nouvellePartie(char* nomPartie, char* chemin);
void CreerFichierSauvegarde(partie info, ptrSection** carte, int** arbre, int taille);
void ouvrirFichier(partie info, ptrSection** carte, int** arbre, int taille);
