#include "arbre.h"
#include "generation.h"
#include "sauvegarder.h"
#include "section.h"
#include "deplacement.h"
#include "joueur.h"
#include <stdio.h>
#include <stdlib.h>
/*
Affichage pour les tests
Sections à ajouter dans une grille
*/

void afficherSection(ptrSection section) {
  printf("x = %d\n", section->x);
  printf("y = %d\n", section->y);
}


int main() {
  /*Générations*/

  printf("\ntaille de la carte : ");
  int taille;
  scanf("%d", &taille);
  ptrSection **carte;
  carte = genererMat(taille);
  terrainMatrice(carte, taille);
  
  //int **test = construireMatrice(carte, taille);
  // int t2 = taille * taille;
  // afficherMatriceV2(construireMatrice(carte, taille), t2);

  // /*Sauvegarde*/

  /*partie jeu;
  NomSauvegarde(jeu.chemin);
  printf("%s\n",jeu.chemin);
  nouvellePartie(jeu.nomPartie, jeu.chemin);
  printf("%s\n", jeu.chemin);
  ptrSection **cartetest = genererMat(taille);
  int **arbretest = construireMatrice(carte, taille);
  CreerFichierSauvegarde(jeu, carte, test, taille);
  ouvrirFichier(jeu, cartetest, arbretest, taille);
  afficheGrille(cartetest, taille);*/
  initStructureFenetre();
  WINDOW *fenetre = creerFenetre(LONGUEUR, LARGEUR, X, Y);
  keypad(fenetre, TRUE);
  nodelay(fenetre, TRUE); 
  //pour eviter de bloquer la fenetre en attendant
  // // qu'une touche sois entrée
  int i = 0;
  Joueur j;
  initPlayer(j);
  initscr();
  creerFenetre(20, 50, 10, 20);
  afficheGrilleNcurses(fenetre,carte,taille);
  int input = getch();
  traiterDeplacement(fenetre, input, carte, j);
  afficheGrilleNcurses(fenetre,carte,taille);
  wrefresh(fenetre);
  getch();
  endwin();

  return 0;
}
