#include <stdio.h>
#include <stdlib.h>
#ifndef H_GENERATION_H
#define H_GENERATION_H
typedef struct Case Case;
typedef struct Case * ptrCase;
#endif

ptrCase** genererMat(int taille);
void terrainMatrice(ptrCase** mat, int taille);
void afficheGrille(ptrCase** mat, int taille);