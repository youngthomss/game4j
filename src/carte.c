/**
 * \file carte.c
 * \brief Gestion de la carte
 * \author Thomas
 *
 * Programme pour la gestion de la carte
 *
 */
#include "carte.h"

/**
 * \fn afficherCarte(ptrSection **carte, int taille)
 * \brief Fonction d'affichage de la carte en fonction d'une matrice.
 * \param carte  Une matrice correspondant à la carte.
 * \param taille La Taille de la matrice.
 * \return void.
 */
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

/**
 * \fn afficher(ptrSection **carte, int taille, ptrJoueur j)
 * \brief Fonction d'affichage de la carte.
 * \param carte  Une matrice correspondant à la carte.
 * \param taille La Taille de la matrice.
 * \param j Un pointeur de joueur
 * \return void.
 */
void afficher(ptrSection **carte, int taille, ptrJoueur j) {
  afficherCarte(carte, taille);
  printf("\033[0;34mEnergie restante : %d\033[0m\n", j->energie);
}

/**
 * \fn afficherInstructions()
 * \brief Fonction d'affichage des instructions.
 * \return void.
 */
 void afficherInstructions() {
  printf("\033[0;32mUtilisez votre pavé numérique pour vous déplacer !\n");
  printf(" 7   8   9\n   ↖ ↑ ↗\n 4 ←   → 6\n   ↙ ↓ ↘\n 1   2   3\n");
  printf("5 pour quitter la partie.\033[0m\n");
}

/**
 * \fn clear()
 * \brief Fonction de nettoyage de la map.
 * \return void.
 */
void clear() { printf("\e[1;1H\e[2J"); }