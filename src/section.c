/**
 * \file section.c
 * \brief Gestion d'une section
 * \author Tom
 *
 * Programme pour la gestion d'une section
 *
 */

#include "section.h"

/**
 * \fn creerSection(int x, int y)
 * \brief Fonction de creation d'une section
 * \param x  Un entier x.
 * \param y Un entier y.
 * \return ptrSection
 */
ptrSection creerSection(int x, int y) {
  int size = sizeof(section);
  ptrSection c = malloc(size);
  c->x = x;
  c->y = y;

  return c;
}
