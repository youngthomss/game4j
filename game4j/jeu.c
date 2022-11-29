#include <stdio.h>
#include <stdlib.h>
#include "./algorithme/generation.h"
#include "./algorithme/generation.c"
#include "./carte/section.h"
#include "./carte/section.c"

/*
Affichage pour les tests
Sections à ajouter dans une grille
*/

void afficherSection(ptrSection section) {
    printf("x = %d\n", section->x);
    printf("y = %d\n", section->y);
}

void afficherArrete(ptrArrete arrete) {
    printf("--- Arrete ---\n");
    afficherSection(arrete->section);
    printf("Distance = %d", arrete->distance);
}


int main() {
    ptrSection s = creerSection(2, 2);
    ptrArrete a = creerArrete(s, 5);
    afficherSection(s);
    afficherArrete(a);
    int taille;
    printf("\ntaille de la carte : ");
    scanf("%d", &taille);
    fflush;
    //printf("\n%d\n",taille);
    ptrSection** carte ;
    carte = genererMat(taille);
    terrainMatrice(carte, taille);
    afficheGrille(carte, taille);
    return 0;
}