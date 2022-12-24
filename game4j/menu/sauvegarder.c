#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sauvegarder.h"

void CreerNomSauvegarde(char* chemin, char* nom){
    printf("Veuillez saisir le chemin d'accès pour vôtre sauvegarde et la finir avec / : ");
    fgets(chemin, taillechemin,stdin);
    fflush;
    chemin[strcspn(chemin, "\n")] = 0;
    printf("Veuillez saisir le nom de votre sauvegarde : ");
    fgets(nom, taillenom,stdin);
    fflush;
    nom[strcspn(nom, "\n")] = 0;
    chemin = strcat(chemin,nom);
    chemin = strcat(chemin,".bin");
}

int main(){
    partie partie;
    CreerNomSauvegarde(partie.chemin, partie.nomPartie);
    printf("%s\n",partie.chemin);
}