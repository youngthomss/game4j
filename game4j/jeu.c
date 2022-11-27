#include <stdio.h>
#include <stdlib.h>
#include "./carte/section.h"

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
    printf("Poids = %d", arrete->poids);
}


int main() {
    ptrSection s = creerSection(2, 2);
    ptrArrete a = creerArrete(s, 5);
    afficherSection(s);
    afficherArrete(a);
    return 0;
}