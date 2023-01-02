#include "../include/arbre.h"
#include "../include/generation.h"
#include "../include/sauvegarder.h"
#include "../include/section.h"
#include "../include/deplacement.h"
#include "../include/joueur.h"
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
  // /*Générations*/

  // ptrSection s = creerSection(2, 2);
  // printf("\ntaille de la carte : ");
  // int taille;
  // scanf("%d", &taille);
  // ptrSection **carte;
  // carte = genererMat(taille);
  // terrainMatrice(carte, taille);
  // afficheGrille(carte, taille);
  // int **test = construireMatrice(carte, taille);
  // int t2 = taille * taille;
  // afficherMatriceV2(construireMatrice(carte, taille), t2);

  // /*Sauvegarde*/

  // partie jeu;
  // // NomSauvegarde(jeu.chemin);
  // // printf("%s\n",jeu.chemin);
  // nouvellePartie(jeu.nomPartie, jeu.chemin);
  // printf("%s\n", jeu.chemin);
  // ptrSection **cartetest = genererMat(taille);
  // int **arbretest = construireMatrice(carte, taille);
  // // CreerFichierSauvegarde(jeu, carte, test, taille);
  // // ouvrirFichier(jeu, cartetest, arbretest, taille);
  // afficheGrille(cartetest, taille);
  // afficherMatriceV2(arbretest, t2);
  // initStructureFenetre();
  WINDOW *fenetre = creerFenetre(LONGUEUR, LARGEUR, X, Y);
  // keypad(fenetre, TRUE);
  // // nodelay(fenetre, TRUE); //pour eviter de bloquer la fenetre en attendant
  // // qu'une touche sois entrée
  // int i = 0;
  // Joueur j;
  // j.position.row = 0;
  // j.position.col = 0;
  // while (i == 0) {
  //   int input = wgetch(fenetre);
  //   traiterDeplacement(fenetre, input, carte, j);
  // }
  ptrSection** m1;
  m1= genererMat(5);
  terrainMatrice(m1, 5);
  initStructureFenetre();
  creerFenetre(20, 50, 10, 20);
  afficheGrilleNcurses(fenetre,m1,5);
  wrefresh(fenetre);
  getch();
  endwin();

  return 0;
}
