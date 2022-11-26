#include <stdio.h>
#include <stdlib.h>
#include "generation.h"

struct Case{
    int terrain;
    // déclaration Case/Arrete 
};

ptrCase** genererMat(int taille){
    ptrCase** mat = malloc(taille*sizeof*mat);
    for(int i=0;i<taille;i++)
        mat[i]=malloc(taille * sizeof(mat[i]));
    return mat;
}

void terrainMatrice(ptrCase** mat, int taille){
    int chance;
    for(int i=0;i<taille;i++){
        for(int j=0;j<taille;j++){
            chance = rand()%100;
            if(chance < 60)
                mat[i][j]->terrain = 0; //case vide
            else if (chance >= 60 && chance < 80)
                mat[i][j]->terrain = -1; //Obstacle
            else if (chance >= 80)
                mat[i][j]->terrain = 1; //Bonus
        }
    }
}

void afficheGrille(ptrCase** mat, int taille){
    for(int i=0; i<taille; i++){
        for(int j=0; j<taille; j++){
            if(i == 0){
                if(j == 0 )
                    printf("   ");
                printf(" %d", j);
                if(j == taille-1 )
                    printf("\n");
            }            
        }
        printf("%d :|",i);
        for(int j=0; j<taille; j++)
            printf("%d|",mat[i][j]->terrain);            
        printf("\n");
    }
}

int main (){
    int taille;
    printf("taille de la carte : ");
    scanf("%d", &taille);
    fflush;
    //printf("\n%d\n",taille);
    ptrCase** carte ;
    carte = genererMat(taille);
    terrainMatrice(carte, taille);
    afficheGrille(carte, taille);
}