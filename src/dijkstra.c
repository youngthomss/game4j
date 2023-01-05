#include "dijkstra.h"
#include "chemin.h"
#include <math.h>

int minDistance(int dist[], bool visite[], int taille) {
  int min = INFINI, min_index;
  for (int v = 0; v < taille; v++)
    if (visite[v] == false && dist[v] <= min)
      min = dist[v], min_index = v;

  return min_index;
}

ptrChemin cheminVersBut(int sommets[], int dernierNoeud, int taille) {
  int n = dernierNoeud;
  ptrChemin tete = NULL;
  while (n != 0) {
    if (sommets[n]) {
      tete = ajouterChemin(
          tete, creerChemin(sommets[n] / taille, sommets[n] % taille));
    }
    n = sommets[n];
  }
  return tete;
}

ptrChemin dijkstra(int **carte, int source, int tailleCarte) {
  int taille = tailleCarte * tailleCarte;
  int dist[taille];
  int sommets[taille];
  bool visite[taille];

  for (int i = 0; i < taille; i++)
    dist[i] = INFINI, visite[i] = false;

  dist[source] = 0;
  sommets[source] = 0;

  for (int count = 0; count < taille - 1; count++) {
    int u = minDistance(dist, visite, taille);
    visite[u] = true;

    for (int v = 0; v < taille; v++)

      if (!visite[v] && carte[u][v] && dist[u] != INFINI &&
          dist[u] + carte[u][v] < dist[v]) {
        dist[v] = dist[u] + carte[u][v];
        sommets[v] = u;
      }
  }

  return cheminVersBut(sommets, taille - 1, tailleCarte);
}

void colorierChemin(ptrSection **carte, ptrChemin chemin) {
  for (ptrChemin p = chemin; p != NULL; p = p->cheminSuivant) {
    carte[p->x][p->y]->terrain = -2;
  }
}