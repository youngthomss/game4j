#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sauvegarder.h"
/*#include "section.c"
#include "arbre.c"
#include "generation.c"*/


void NomSauvegarde(char* chemin){
    printf("Veuillez saisir le chemin d'accès pour vos sauvegarde et la finir avec / : ");
    fgets(chemin, taillechemin,stdin);
    fflush;
    chemin[strcspn( chemin, "\n")] = 0;
    //chemin = strcat(chemin,".bin");
}

void nouvellePartie(char* nomPartie, char* chemin){
    printf("Veuillez saisir le nom de votre sauvegarde : ");
    fgets(nomPartie, taillenom,stdin);
    fflush;
    nomPartie[strcspn(nomPartie, "\n")] = 0;
    chemin = strcat(chemin,nomPartie);
    chemin = strcat(chemin,".bin");
}

void CreerFichierSauvegarde(partie info, ptrSection** carte, int** arbre, int taille){
    FILE* Sauvegarde = fopen(info.chemin, "wb");
    int t2 = taille*taille;
    for(int i=0;i<taille;i++){
        for(int j = 0;j<taille;j++)
            fwrite(&carte[i][j], sizeof(carte[i][j]), 1, Sauvegarde); 
    }
    for(int i=0;i<t2;i++){
        for(int j = 0;j<t2;j++)
            fwrite(&arbre[i][j], sizeof(arbre[i][j]), 1, Sauvegarde);
    }
    fclose(Sauvegarde);
}

void ouvrirFichier(partie info, ptrSection** carte, int** arbre, int taille){
    FILE* Sauvegarde = fopen(info.chemin, "rb");
    int t2 = taille*taille;
    for(int i=0;i<taille;i++){
        for(int j = 0;j<taille;j++)
            fread(&carte[i][j], sizeof(carte[i][j]), 1, Sauvegarde); 
    }
    for(int i=0;i<t2;i++){
        for(int j = 0;j<t2;j++)
            fread(&arbre[i][j], sizeof(arbre[i][j]), 1, Sauvegarde); 
    }
    fclose(Sauvegarde);
}
/*
int main(){
    partie game;
    int taille =10;
    int t2=taille*taille;
    ptrSection** carte ;
    carte = genererMat(taille);
    terrainMatrice(carte, taille);
    afficheGrille(carte, taille);
    int ** arbretest=construireMatrice(carte,taille);
    for(int i = 0;i<t2;i++){
        for(int j=0;j<t2;j++)
        arbretest[i][j]=0;
    }
    int ** test= construireMatrice(carte,taille);
    afficherMatriceV2(test,t2);
    afficherMatriceV2(arbretest,t2);
    //NomSauvegarde(game.chemin);
    nouvellePartie(game.nomPartie,game.chemin);
    printf("%s\n",game.chemin);
    ptrSection ** cartetest = genererMat(taille);
    CreerFichierSauvegarde(game, carte, test, taille);
    printf("Vali\n");
    ouvrirFichier(game, cartetest, arbretest, taille);
    printf("Vali2\n");
    afficheGrille(cartetest, taille);
    afficherMatriceV2(arbretest,t2);
}*/