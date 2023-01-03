#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "position.h"
typedef struct Joueur* ptrJoueur;
typedef struct Joueur joueur;

struct Joueur {
    ptrPosition position;
    int energie;
};

ptrJoueur initPlayer();
