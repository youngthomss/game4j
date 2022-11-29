#include <ncurses.h> 
#include "deplacement.h"  
enum direction{ HAUT = 1, DROITE = 2, BAS = 3, GAUCHE = 3}; 

//En incluant la bibliothèque ncurses.h, nous n'avons plus besoin d'inclure la bibliothèque stdio.h car celle ci est inclue implicitement dans ncurses.h

// Lors de la compilation avec gcc, il faut spécifier que vous utilisez la bibliothèque Ncurses et pour cela il vous faut rajouter l'option lncurses. 
//Exemple gcc -lncurses -o HelloWorld HelloWorld.c



int main(void)
{	

 initscr();              // Initialise la structure WINDOW et autres paramètres
 noecho();
 cbreak();


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

//la fenetre doit être paramétré au préalable comme ci-dessus


int DeplacementInput(WINDOW *fenetre){ 
    keypad(fenetre, TRUE); /* pour récupérer les événements du clavier */
        //nodelay(fenetre, TRUE); //pour eviter de bloquer la fenetre en attendant qu'une touche sois entrée
    int input= wgetch(fenetre);
  

    switch (input){    

      case  KEY_UP  : mvwprintw(fenetre, 10, 25, "Tu te déplaces en haut");
      wrefresh(fenetre); 
        return HAUT;   break;

      case KEY_RIGHT: mvwprintw(fenetre, 10, 25, "Tu te déplaces à droite"); 
      wrefresh(fenetre);
        return DROITE; break;
 
      case KEY_DOWN : mvwprintw(fenetre, 10, 25, "Tu te déplaces en bas");
      wrefresh(fenetre); 
        return BAS;    break;

      case KEY_LEFT : mvwprintw(fenetre, 10, 25, "Tu te déplaces à gauche");
      wrefresh(fenetre); 
        return GAUCHE; break;

      default       : mvwprintw(fenetre, 1, 1, "Erreur, choisissez une bonne direction");
      wrefresh(fenetre);
        return 5;      break;
    }

wrefresh(fenetre);
return 0;
};

while (DeplacementInput(fenetre) == 5 ){       // boucle while ( tant que l"entree n'est pas une direction, retapez la toouche 

}


    getch();                // On attend que l'utilisateur appui sur une touche pour quitter
    endwin();               // Restaure les paramètres par défaut du terminal
    
    return 0;
}




//DeplacementInput(fenetre);

    //initscr();              // Initialise la structure WINDOW et autres paramètres 
     //move(LINES - 1, COLS - 1);  // Déplace le curseur tout en bas à droite de l'écran
    //addch('.');                 // Écrit le caractère . au nouvel emplacement
    
    //curs_set(0);            // Rend le curseuur physique invisible
    //printw("Hello World");  // Écrit Hello World à l'endroit où le curseur logique est positionné
   // refresh();              // Rafraîchit la fenêtre courante afin de voir le message apparaître

    //keypad(stdscr,TRUE);