#include "arbre.h"
#include "deplacement.h"
#include "generation.h"
#include "joueur.h"
#include "sauvegarder.h"
#include "section.h"
#include "carte.h"


int main() {
  /*Générations*/
  printf("\nTaille de la carte : ");
  int taille;
  scanf("%d", &taille);
  ptrSection **carte;
  carte = genererMat(taille);
  terrainMatrice(carte, taille);
  clear();

  /*Sauvegarde*/

  /* */
  int deplacement;
  bool quit = false;
  ptrJoueur j = initPlayer(taille);
  while (!quit) {
    afficherInstructions();
    afficher(carte, taille, j);
    printf("Entrez votre déplacement : ");
    scanf("%d", &deplacement);
    traiterDeplacement(carte, deplacement, j, taille);
    clear();

    // Le joueur est sur la dernière case
    if (carte[taille-1][taille-1]->terrain == 2) {
      printf("\033[0;32mVous avez gagné !\033[0m\n");
      quit = !quit;
    }

    // Le joueur n'a plus d'énergie
    if (j->energie == 0) {
      printf("\033[0;31mVous n'avez plus d'énergie, c'est la fin !\033[0m\n");
      quit = !quit;
    }

    // Le joueur quitte la partie
    if (deplacement == 5) {
      printf("\033[0;31mVous avez quitté la partie :(\033[0m\n");
      quit = !quit;
    }
  }
  afficher(carte, taille, j);
  return 0;
}
