#include "carte.h"

void afficherCarte(ptrSection **carte, int taille) {
  printf("┌");
  for (int i = 0; i < taille; i++)
    printf("───");
  printf("┐\n");

  for (int j = 0; j < taille; j++) {
    printf("│");
    for (int i = 0; i < taille; i++) {
      int terrain = carte[j][i]->terrain;
      if (terrain == -2) {
        printf(" 🔵");
      }
      if (terrain == -1) {
        printf(" 🏢");
      }
      if (terrain == 0) {
        printf(" · ");
      }
      if (terrain == 1) {
        printf(" 🍎");
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
  afficherCarte(carte, taille);
  printf("\033[0;34mEnergie restante : %d\033[0m\n", j->energie);
}

void afficherInstructions() {
  printf("\033[0;32m\nUtilisez votre pavé numérique pour vous déplacer !\n");
  printf(" 7   8   9\n   ↖ ↑ ↗\n 4 ←   → 6\n   ↙ ↓ ↘\n 1   2   3\n");
  printf("5 pour quitter la partie.\033[0m\n");
}

void clear() { printf("\e[1;1H\e[2J"); }