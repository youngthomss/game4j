/**
 * \file position.c
 * \brief Gestion des positions
 * \author Aniss Thomas
 *
 * Programme pour la gestion de la position
 *
 */

#include "position.h"

/**
 * \fn creerPosition()
 * \brief Fonction de creation d'une position
 * \return ptrPosition
 */
 ptrPosition creerPosition() {
  int size = sizeof(position);
  ptrPosition p = malloc(size);

  p->row = 0;
  p->col = 0;

  return p;
}