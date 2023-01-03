#include "dijkstra.h"
#include "chemin.h"
#include <math.h>

int minDistance(int dist[], bool visite[], int taille) {
  // Initialize min value
  int min = INFINI, min_index;
  for (int v = 0; v < taille; v++)
    if (visite[v] == false && dist[v] <= min)
      min = dist[v], min_index = v;

  return min_index;
}

ptrChemin nouveauChemin(int n, int taille) {
  int x = 0;
  int y = 0;
  for (int i = 0; i<n; i++) {
    x += 1;
    if (i%taille == 0) {
      y += 1;
      x = 0;
    }
  }
  // printf("x: %d, y : %d\n", x, y);
  ptrChemin c = creerChemin(x, y);
  afficherChemins(c);
  return c;
}

ptrChemin printParent(int parent[], int endnode, int taille) {
  int n = endnode;
  ptrChemin tete = NULL;
  while (n != 0) {
    if (parent[n]) {
      tete = ajouterChemin(tete, nouveauChemin(parent[n], taille));
      printf("%d -> ", parent[n]);
    }
    n = parent[n];
  }
  printf("\n");
  return tete;
}

void dijkstra(int **graph, int src, int tailleCarte) {
  int taille = tailleCarte*tailleCarte;
  int dist[taille];
  int parent[taille];
  bool visite[taille];

  for (int i = 0; i < taille; i++)
    dist[i] = INFINI, visite[i] = false;

  dist[src] = 0;
  parent[src] = 0;

  for (int count = 0; count < taille - 1; count++) {
    int u = minDistance(dist, visite, taille);
    visite[u] = true;

    for (int v = 0; v < taille; v++)

      if (!visite[v] && graph[u][v] && dist[u] != INFINI &&
          dist[u] + graph[u][v] < dist[v]) {
        dist[v] = dist[u] + graph[u][v];
        parent[v] = u;
      }
  }

  printParent(parent, taille-1, tailleCarte);
}
