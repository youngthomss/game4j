#include "djikstra.h"
#include <time.h>


int** genererMatrice(int taille) {
    srand(time(NULL));
    int** matrice = malloc(sizeof(int)*taille*taille);
    for (int i=0; i<taille; i++) {
        matrice[i] = malloc(sizeof(int)*taille);
    }

    return matrice;
}

void remplirMatrice(int** matrice, int taille) {
    srand(time(NULL));
    for (int i=0; i<taille; i++) {
        for (int j=0; j<taille; j++) {
            int random = rand() % 10 + 1;
            matrice[i][j] = random;
            matrice[j][i] = random;
        }
        matrice[i][i] = 0;
    }
}

void afficherMatrice(int** matrice, int taille) {
    for (int i=0; i<taille; i++) {
        for (int j=0; j<taille; j++) {
            printf("|%d|", matrice[i][j]);
        }
        printf("\n");
    }
}

ptrCoordonnees djikstra(int** matrice){
    // A faire : une liste chainee de coordonnes donnée par l'algo de djikstra
}


int main() {
    int** matrice = genererMatrice(16);
    remplirMatrice(matrice, 16);
    afficherMatrice(matrice, 16);
    return 0;
}
