#include <stdio.h>
#include <stdlib.h>
#include "../algorithme/generation.h"
#include "../carte/section.h"
typedef struct Partie partie;
typedef struct Partie* ptrPartie;
#define taillechemin 100
#define taillenom 30

struct Partie{
    char chemin[taillechemin];
    char nomPartie[taillenom];
};

void CreerNomSauvegarde(char* chemin, char* nom);