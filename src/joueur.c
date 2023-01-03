/**
 * \file joueur.c
 * \brief Gestion du joueur
 * \author Thomas Aniss
 *
 * Programme pour la gestion du joueur
 *
 */

#include "joueur.h"

/**
 * \fn initPlayer(int energie)
 * \brief Fonction d'initialisation d'un joueur
 * \param energie Energie du joueur
 * \return ptrJoueur
 */
ptrJoueur initPlayer(int energie) {
  int size = sizeof(joueur);
  ptrJoueur j = malloc(size);
  j->position = creerPosition();
  j->energie = energie;

  return j;
}
