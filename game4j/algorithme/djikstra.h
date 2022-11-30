#pragma once
#include <stdio.h>
#include <stdlib.h>
typedef struct Coordonnees coordonnees;
typedef struct Coordonnees* ptrCoordonnees;

struct Coordonnees {
    int x;
    int y;
    ptrCoordonnees coordonnees;
};

ptrCoordonnees djikstra(int** matrice);
int** genererMatrice(int taille);
void remplirMatrice(int** matrice, int taille);