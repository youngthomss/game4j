#include <stdio.h>
#include <stdlib.h>
#include "arbre.h"
#include "generation.h"
#include "sauvegarder.h"
#include "section.h"
#include "arbre.h"
#include "generation.h"
#include "sauvegarder.h"
/*
Affichage pour les tests
Sections à ajouter dans une grille
*/

void afficherSection(ptrSection section) {
    printf("x = %d\n", section->x);
    printf("y = %d\n", section->y);
}


int main() {
/*Générations*/

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

/*Sauvegarde*/

    partie jeu;
    NomSauvegarde(jeu.chemin);
    //printf("%s\n",jeu.chemin);
    nouvellePartie(jeu.nomPartie,jeu.chemin);
    printf("%s\n",jeu.chemin);
    ptrSection ** cartetest = genererMat(taille);
    int ** arbretest = construireMatrice(carte, taille);
    CreerFichierSauvegarde(jeu, carte, test, taille);
    ouvrirFichier(jeu, cartetest, arbretest, taille);
    afficheGrille(cartetest, taille);
    afficherMatriceV2(arbretest,t2);

    return 0;
}
