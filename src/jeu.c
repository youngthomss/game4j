#include "../include/arbre.h"
#include "../include/deplacement.h"
#include "../include/generation.h"
#include "../include/joueur.h"
#include "../include/sauvegarder.h"
#include "../include/section.h"
#include <stdio.h>
#include <stdlib.h>
/*
Affichage pour les tests
Sections à ajouter dans une grille
*/

void afficherSection(ptrSection section) {
  printf("x = %d\n", section->x);
  printf("y = %d\n", section->y);
}

void afficherTerrain(ptrSection **carte, int taille) {
  printf("┌");
  for (int i = 0; i < taille; i++)
    printf("───");
  printf("┐\n");

  for (int j = 0; j < taille; j++) {
    printf("│");
    for (int i = 0; i < taille; i++) {
      int terrain = carte[j][i]->terrain;
      if (terrain == 0) {
        printf(" · ");
      }
      if (terrain == -1) {
        printf(" 🚙");
      }
      if (terrain == 1) {
        printf(" ★ ");
      }
      if (terrain == 2) {
        printf(" 🐢");
      }
    }
    printf("│\n");
  }

  printf("└");
  for (int i = 0; i < taille; i++)
    printf("───");
  printf("┘\n");
}

void afficher(ptrSection **carte, int taille, ptrJoueur j) {
  afficherTerrain(carte, taille);
  printf("Terrain derniere case : %d\n", carte[taille-1][taille-1]->terrain);
  printf("Energie restante : %d\n", j->energie);
  printf("Entrez votre déplacement : ");
}

int main() {
  /*Générations*/
  printf("\nTaille de la carte : ");
  int taille;
  scanf("%d", &taille);
  ptrSection **carte;
  carte = genererMat(taille);
  terrainMatrice(carte, taille);

  /*Sauvegarde*/

  /* */
  int deplacement;
  bool quit = false;
  carte[0][0]->terrain = 2;
  ptrJoueur j = initPlayer();
  
  while (!quit) {
    afficher(carte, taille, j);
    scanf("%d", &deplacement);
    traiterDeplacement(carte, deplacement, j, taille);
    printf("\e[1;1H\e[2J");
    if (carte[taille-1][taille-1]->terrain == 2) {
      printf("Vous avez gagné !\n");
      quit = true;
    }

    if (j->energie == 0) {
      printf("Vous n'avez plus d'énergie, c'est la fin !\n");
      quit = true;
    }

    if (deplacement == 5) {
      printf("Vous avez quitté la partie :(\n");
      quit = true;
    }
  }
  afficherTerrain(carte, taille);
  return 0;
}
