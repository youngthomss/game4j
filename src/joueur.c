#include "joueur.h"

ptrJoueur initPlayer(int energie) {
  int size = sizeof(joueur);
  ptrJoueur j = malloc(size);
  j->position = creerPosition();
  j->energie = energie;

  return j;
}
