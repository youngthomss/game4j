#include <ncurses.h> 
#include "deplacement.h"  
enum direction{ HAUT = 1, DROITE = 2, BAS = 3, GAUCHE = 3, PAVE_HAUT='8',PAVE_DROIT='6',PAVE_BAS='2', PAVE_GAUCHE='4'}; 

//En incluant la bibliothèque ncurses.h, nous n'avons plus besoin d'inclure la bibliothèque stdio.h car celle ci est inclue implicitement dans ncurses.h

// Lors de la compilation avec gcc, il faut spécifier que vus utilisez la bibliothèque Ncurses et pour cela il vous faut rajouter l'option lncurses. 
//Exemple gcc -lncurses -o HelloWorld HelloWorld.c



int DeplacementInput(WINDOW *fenetre){ 
    keypad(fenetre, TRUE); /* pour récupérer les événements du clavier */
        //nodelay(fenetre, TRUE); //pour eviter de bloquer la fenetre en attendant qu'une touche sois entrée
    
  int input= wgetch(fenetre);
  

    switch (input){    

      case  PAVE_HAUT   : mvwprintw(fenetre, 10, 25, "Tu te déplaces en haut");
      wrefresh(fenetre); 
        return HAUT;   break;

      case  PAVE_DROIT  : mvwprintw(fenetre, 10, 25, "Tu te déplaces à droite"); 
      wrefresh(fenetre);
        return DROITE; break;
 
      case  PAVE_BAS    : mvwprintw(fenetre, 10, 25, "Tu te déplaces en bas");
      wrefresh(fenetre); 
        return BAS;    break;

      case  PAVE_GAUCHE : mvwprintw(fenetre, 10, 25, "Tu te déplaces à gauche");
      wrefresh(fenetre); 
        return GAUCHE; break;

      default           : mvwprintw(fenetre, 10, 15, "Erreur, choisissez une bonne direction");
      wrefresh(fenetre);
        return 5;      break;
    }

return 0;
};

//-----------------------------------------------------------------------------------------


int main(void)
{	

  initscr();              // Initialise la structure WINDOW et autres paramètres
  noecho();
  //cbreak();
  curs_set(0);

//parametre la taille de la fenetre
  int longueur, largeur, x, y;
  largeur=70;
  longueur=25;
  x=10;
  y=10;


//Creer une fenetre pour l'input
  WINDOW * fenetre = newwin(longueur, largeur, x, y);
  box(fenetre, 0, 0);
  refresh();
  wrefresh(fenetre);

//la fenetre doit être paramtré au préalable comme ci-dessus


int i = 0; 

while (i == 0 ){       // boucle while ( tant que l"entree n'est pas une direction, retapez la toouche 


    DeplacementInput(fenetre);
    werase(fenetre);
    box(fenetre, 0, 0);     // recree la partie de la bordure droite supp
    wrefresh(fenetre);
    DeplacementInput(fenetre);
    
    } 


  getch();              
  endwin();            
  return 0;
}