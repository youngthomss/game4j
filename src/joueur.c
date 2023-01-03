#include "joueur.h"


ptrJoueur initPlayer() {
  int size = sizeof(joueur);
  ptrJoueur j = malloc(size);
  j->position = creerPosition();
  j->energie = 50;

  return j;
}
