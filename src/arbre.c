/**
 * \file arbre.c
 * \brief Gestion des arbres
 * \author Tom
 *
 * Programme pour la gestion des arbres
 *
 */

#include "arbre.h"
#include "string.h"

/**
 * \fn convertCaseToInt(int x, int y, int taille)
 * \brief Fonction de création d'une nouvelle instance d'un objet Str_t.
 * \param x  Un entier x.
 * \param y Un entier y.
 * \param taille La Taille de la matrice.
 * \return Un entier.
 */
int convertCaseToInt(int x, int y, int taille) { return x * taille + y; }

/**
 * \fn afficherMatriceV2(int **mat, int taille1)
 * \brief Fonction d'affichage de matrice
 * \param mat Une matrice.
 * \param taille La Taille de la matrice.
 * \return void
 */
void afficherMatriceV2(int **mat, int taille1) {
  for (int i = 0; i < taille1; i++) {
    for (int j = 0; j < taille1; j++) {
      printf("%d ", mat[i][j]);
    }
    printf("\n");
  }
}

/**
 * \fn creerDistance(ptrSection case1, ptrSection case2, int **mat, int taille)
 * \brief Fonction de création de distance.
 * \param case1 Une case de l'arbre.
 * \param case2 Une case de l'arbre.
 * \param mat Une matrice.
 * \param taille La Taille de la matrice.
 * \return void
 */
void creerDistance(ptrSection case1, ptrSection case2, int **mat, int taille) {
  int indexX = convertCaseToInt(case1->x, case1->y, taille);
  int indexY = convertCaseToInt(case2->x, case2->y, taille);
  int distance = rand() % 10 + 1;
  if (mat[indexX][indexY] == 0) {
    mat[indexX][indexY] = distance;
    mat[indexY][indexX] = distance;
  }
}

/**
 * \fn **genererMatrice(int taille1)
 * \brief Fonction de création d'une matrice.
 * \param taille La Taille de la matrice.
 * \return une matrice
 */
int **genererMatrice(int taille1) {
  srand(time(NULL));
  int **matrice = malloc(sizeof(int) * taille1 * taille1);
  for (int i = 0; i < taille1; i++) {
    matrice[i] = malloc(sizeof(int) * taille1);
  }
  for (int i = 0; i < taille1; i++) {
    for (int j = 0; j < taille1; j++) {
      matrice[i][j] = 0;
    }
  }
  return matrice;
}

/**
 * \fn **construireMatrice(ptrSection **matrice, int taille)
 * \brief Fonction de construction d'une matrice.
 * \param mat Une matrice.
 * \param taille La Taille de la matrice.
 * \return une matrice.
 */
 int **construireMatrice(ptrSection **matrice, int taille) {
  int taille_mat = taille * taille;
  int **mat = genererMatrice(taille_mat);
  for (int i = 0; i < taille; i++) {
    for (int j = 0; j < taille; j++) {
      if (matrice[i][j]->terrain != -1) {
        if (j == 0 && i != taille - 1) {
          if (matrice[i][j + 1]->terrain != -1) {
            creerDistance(matrice[i][j], matrice[i][j + 1], mat, taille);
          }
          if (matrice[i + 1][j + 1]->terrain != -1) {
            creerDistance(matrice[i][j], matrice[i + 1][j + 1], mat, taille);
          }
          if (matrice[i + 1][j]->terrain != -1) {
            creerDistance(matrice[i][j], matrice[i + 1][j], mat, taille);
          }
        } else if (i == taille - 1 && j != taille - 1) {
          if (matrice[i][j + 1]->terrain != -1) {
            creerDistance(matrice[i][j], matrice[i][j + 1], mat, taille);
          }
        }

        else if (i != taille - 1 && j == taille - 1) {
          if (matrice[i + 1][j]->terrain != -1) {
            creerDistance(matrice[i][j], matrice[i + 1][j], mat, taille);
          }
          if (matrice[i + 1][j - 1]->terrain != -1) {
            creerDistance(matrice[i][j], matrice[i + 1][j - 1], mat, taille);
          }
        }

        else if (i != taille - 1 && j != taille - 1) {
          if (matrice[i][j + 1]->terrain != -1) {
            creerDistance(matrice[i][j], matrice[i][j + 1], mat, taille);
          }
          if (matrice[i + 1][j + 1]->terrain != -1) {
            creerDistance(matrice[i][j], matrice[i + 1][j + 1], mat, taille);
          }
          if (matrice[i + 1][j]->terrain != -1) {
            creerDistance(matrice[i][j], matrice[i + 1][j], mat, taille);
          }
          if (matrice[i + 1][j - 1]->terrain != -1) {
            creerDistance(matrice[i][j], matrice[i + 1][j - 1], mat, taille);
          }
        }
      }
    }
  }

  return mat;
}
