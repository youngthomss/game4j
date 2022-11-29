#include <stdio.h>
#include <stdlib.h>
#pragma once
#include "../carte/section.h"

ptrSection** genererMat(int taille);
void terrainMatrice(ptrSection** mat, int taille);
void afficheGrille(ptrSection** mat, int taille);