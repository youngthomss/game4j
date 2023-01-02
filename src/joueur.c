#include "../include/joueur.h"
#include "../include/deplacement.h"
#include "../include/generation.h"
#include <curses.h>
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>


void initPlayer(Joueur joueur) {
  joueur.position.row = 0;
  joueur.position.col = 0;
  joueur.Energie = 50;
}

void afficheGrilleNcurses(WINDOW *fenetre, ptrSection **mat, int taille) {
  for (int i = 0; i < taille; i++) {
    for (int j = 0; j < taille; j++) {
      move(i + 11, j + 21);

      if (mat[i][j]->terrain == 0) {
        addch('.');
        wrefresh(fenetre);
      }
      if (mat[i][j]->terrain == 1) {
        addch('*');
        wrefresh(fenetre);
      }
      if (mat[i][j]->terrain == -1) {
        addch('?');
        wrefresh(fenetre);
      }
      if (mat[i][j]->terrain == 2) {
        addch('%');
        wrefresh(fenetre);
      }
      if (mat[i][j]->terrain == 3) {
        addch('O');
        wrefresh(fenetre);
      }
    }
    wrefresh(fenetre);
  }
}