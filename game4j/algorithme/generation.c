#include <stdio.h>
#include <stdlib.h>
#include "generation.h"

ptrSection** genererMat(int taille){
    ptrSection** mat = (ptrSection**)malloc(taille*sizeof*mat);
    for(int i=0;i<taille;i++){
        mat[i] = (ptrSection*)malloc(taille*sizeof(mat[i]));
        for(int j=0;j<taille;j++)
            mat[i][j] = malloc(sizeof(mat[i][j]));
    }
    return mat;
}

void terrainMatrice(ptrSection** mat, int taille){
    int chance;
    for(int i=0;i<taille;i++){
        for(int j=0;j<taille;j++){
            chance = rand()%100;
            if(chance < 60)
                mat[i][j]->terrain = 0; //Section vide
            else if (chance >= 60 && chance < 80)
                mat[i][j]->terrain = -1; //Obstacle
            else if (chance >= 80)
                mat[i][j]->terrain = 1; //Bonus   
        }
    }
    mat[0][0]->terrain=0;
    mat[taille-1][taille-1]->terrain=0;
}

void afficheGrille(ptrSection** mat, int taille){
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
            printf(" %d|",mat[i][j]->terrain);            
        printf("\n");
    }
}
