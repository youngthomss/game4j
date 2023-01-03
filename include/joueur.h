#pragma once
#include "commons.h"
#include "position.h"
typedef struct Joueur* ptrJoueur;
typedef struct Joueur joueur;

struct Joueur {
    ptrPosition position;
    int energie;
};

ptrJoueur initPlayer(int energie);
