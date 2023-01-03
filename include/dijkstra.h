#pragma once
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#define INFINI 9999 

int minDistance(int dist[], bool sptSet[], int taille);
void printSolution(int dist[], int taille);
void dijkstra(int **graph, int src, int taille);
