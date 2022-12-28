#ifndef CHARGEMENT_H
#define CHARGEMENT_H

#include <stdio.h>
#include <stdlib.h>

/* Structure Partie:  permet de stocker les paramètres d'une partie           */
typedef struct partie {
    int     L; // le nb de lignes du plateau de jeu
    int     C; // le nb de colonne du plateau de jeu
    Joueur     joueur; // la position de Pacman dans le plateau
    int     nbbonus; // le nombre de bonus dispo sur le terrain
    } Partie;

#endif