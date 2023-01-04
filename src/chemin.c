#include "chemin.h"
#include <stdlib.h>

ptrChemin creerChemin(int x, int y) {
  ptrChemin chemin = malloc(sizeof(chemin));
  chemin->x = x;
  chemin->y = y;
  chemin->cheminSuivant = malloc(sizeof(chemin));
  chemin->cheminSuivant = NULL;
  return chemin;
}

ptrChemin ajouterChemin(ptrChemin tete, ptrChemin c) {
    if (tete==NULL) {return c;}
    ptrChemin p=tete,pred=NULL;
    for(p=tete; p!=NULL; p=p->cheminSuivant){pred=p;}

    if (pred==NULL){c->cheminSuivant=tete; return c;}
    c->cheminSuivant=pred->cheminSuivant;
    pred->cheminSuivant=c;

    return tete;
}

void afficherChemins(ptrChemin c) {
  if (c != NULL) {
    printf("(x : %d, y : %d)\n", c->x, c->y);
  } else {
    printf("NULL\n");
  }
}

void afficheListeChemins(ptrChemin tete) {
  ptrChemin p;
  for (p = tete; p != NULL; p = p->cheminSuivant) {
    afficherChemins(p);
  }
}
