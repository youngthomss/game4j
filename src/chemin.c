#include "chemin.h"

ptrChemin creerChemin(int x, int y) {
  ptrChemin chemin = malloc(sizeof(chemin));
  chemin->x = x;
  chemin->y = y;
  chemin->cheminSuivant = NULL;
  return chemin;
}

ptrChemin ajouterChemin(ptrChemin tete, ptrChemin c) {
  if (tete == NULL) {
    return c;
  }
  ptrChemin p = tete;
  for (ptrChemin p = tete; p->cheminSuivant != NULL; p = p->cheminSuivant) {
  }
  p->cheminSuivant = c;
  return tete;
}

void afficherChemins(ptrChemin c) {
    printf("(x : %d, y : %d)", c->x, c->y);
}

