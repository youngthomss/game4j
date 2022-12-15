#include <stdio.h>
#include <stdlib.h>
#include "./carte/arbre.h"
#include "generation.h"

/*
Affichage pour les tests
Sections à ajouter dans une grille
*/

void afficherSection(ptrSection section) {
    printf("x = %d\n", section->x);
    printf("y = %d\n", section->y);
}


int main() {
    ptrSection s = creerSection(2, 2);
    printf("\ntaille de la carte : ");
    int taille;
    scanf("%d", &taille);
    ptrSection** carte ;
    carte = genererMat(taille);
    terrainMatrice(carte, taille);
    afficheGrille(carte,taille);
    int ** test= construireMatrice(carte,taille);
    int t2=taille*taille;
    afficherMatriceV2(construireMatrice(carte,taille),t2);

    return 0;
}