#pragma once
#include "chemin.h"
#include "commons.h"
#include "section.h"
#define INFINI 9999

int minDistance(int dist[], bool sptSet[], int taille);
ptrChemin dijkstra(int **graph, int src, int taille);
ptrChemin cheminVersBut(int parent[], int endnode, int taille);
void colorierChemin(ptrSection **carte, ptrChemin chemin);