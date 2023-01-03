#pragma once
#include "commons.h"
#include "section.h"

ptrSection** genererMat(int taille);
void terrainMatrice(ptrSection** mat, int taille);
void afficheGrille(ptrSection** mat, int taille);