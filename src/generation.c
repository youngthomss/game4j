/**
 * \file generation.c
 * \brief Gestion des matrices
 * \author Thibault
 *
 * Programme pour la gestion des matrices
 *
 */

#include "generation.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * \fn **genererMat(int taille)
 * \brief Fonction de generation d'une matrice
 * \param taille La Taille de la matrice.
 * \return ptrSection
 */
 ptrSection **genererMat(int taille) {
  ptrSection **mat = (ptrSection **)malloc(taille * sizeof *mat);
  for (int i = 0; i < taille; i++) {
    mat[i] = (ptrSection *)malloc(taille * sizeof(mat[i]));
    for (int j = 0; j < taille; j++)
      mat[i][j] = malloc(sizeof(mat[i][j]));
  }
  return mat;
}

/**
 * \fn terrainMatrice(ptrSection **mat, int taille)
 * \brief Fonction de remplissage d'une matrice
 * \param mat Une matrice.
 * \param taille La Taille de la matrice.
 * \return void
 */
void terrainMatrice(ptrSection **mat, int taille) {
  srand(time(NULL));
  int chance;
  for (int i = 0; i < taille; i++) {
    for (int j = 0; j < taille; j++) {
      mat[i][j]->x = i;
      mat[i][j]->y = j;
      chance = rand() % 100;
      if (chance < 60)
        mat[i][j]->terrain = 0; // Section vide
      else if (chance >= 60 && chance < 80)
        mat[i][j]->terrain = -1; // Obstacle
      else if (chance >= 80)
        mat[i][j]->terrain = 1; // Bonus
    }
  }
  mat[0][0]->terrain = 2; // Joueur
  mat[taille - 1][taille - 1]->terrain = 0;
}

/**
 * \fn afficheGrille(ptrSection **mat, int taille)
 * \brief Fonction d'affichage  d'une matrice
 * \param mat Une matrice.
 * \param taille La Taille de la matrice.
 * \return void
 */
void afficheGrille(ptrSection **mat, int taille) {
  for (int i = 0; i < taille; i++) {
    for (int j = 0; j < taille; j++) {
      if (i == 0) {
        if (j == 0)
          printf("   ");
        printf(" %d", j);
        if (j == taille - 1)
          printf("\n");
      }
    }
    printf("%d :|", i);
    for (int j = 0; j < taille; j++)
      printf(" %d|", mat[i][j]->terrain);
    printf("\n");
  }
}
