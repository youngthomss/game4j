#include <stdio.h>
#include <stdlib.h>
#include "./carte/arbre.h"

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
    const int taille = 5;
    ptrSection s = creerSection(2, 2);
    //printf("\ntaille de la carte : ");
    //scanf("%d", &taille);
    //fflush;
    ptrSection** carte ;
    carte = genererMat(taille);
    terrainMatrice(carte, taille);
    afficheGrille(carte,taille);
    int ** test= construireMatrice(carte,taille);
    int t2=taille*taille;
    afficherMatriceV2(construireMatrice(carte,taille),t2);
    
    return 0;
}