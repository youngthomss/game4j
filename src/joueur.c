#include <curses.h>
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>  
#include "../include/joueur.h" 
#include "../include/deplacement.h"
#include "../include/generation.h"



/**int main (){ 
    initStructureFenetre();
    creerFenetre(50, 50, 10, 20);
    afficheGrilleNcurses(genererMat(5), 5);
}*/


void initPlayer(Joueur joueur){
    joueur.position.row = 0;
    joueur.position.col = 0;
    joueur.Energie = 50;
}

void afficheGrilleNcurses(WINDOW* fenetre, ptrSection** mat, int taille){
    for(int i=0; i<taille; i++){
        for(int j=0; j<taille; j++){
            if(i == 0){
                if(j == 0 )
                mvwprintw(fenetre, 2*j,i+(i+1)*3, "%3d",mat[i][j]);
                    mvwprintw(fenetre,5,1,"   ");
                mvwprintw(fenetre,1,1," %d", j);
                wrefresh(fenetre);
                if(j == taille-1 )
                    mvwprintw(fenetre,1,1,"\n");
                    wrefresh(fenetre);
            }            
            // if(mat[i][j] -> terrain == 0){
            //    // mvwprintw(fenetre,i+5, j+5," ");
            //     mvwprintw(fenetre, 2*j,i+(i+1)*3," XCXXXXXXX");
            // }
            // if(mat[i][j] -> terrain == 1){
            //     mvwprintw(fenetre,i+5, j+5,".");
          
            // }
            // if(mat[i][j] -> terrain == -1){
            //     mvwprintw(fenetre,i+5, j+5,"*");
             
            // }
            // if(mat[i][j] -> terrain == 2){
            //     mvwprintw(fenetre,0, 0,"X");
                
            // }
            // if(mat[i][j] -> terrain == 3){
            //     mvwprintw(fenetre,i+5, j+5,"O");
                
            // } else { 
            // mvwprintw(fenetre, 2,3," XCXXXXXXX");
            // }
        }
        mvwprintw(fenetre,1,1,"%d :|",i);
        for(int j=0; j<taille; j++)
            mvwprintw(fenetre,1,1," %d|",mat[i][j]->terrain);            
        mvwprintw(fenetre,1,1,"\n");
        wrefresh(fenetre);
    }
    wrefresh(fenetre);
}
