			DOC NCURSES


lien doc: http://www.linuxfocus.org/Francais//Archives/lf-2002_03-0233.pdf

#include <ncurses.h>     
En incluant la bibliothèque ncurses.h, nous n'avons plus besoin d'inclure la bibliothèque stdio.h car celle ci est inclue implicitement dans ncurses.h

Lors de la compilation avec gcc, il faut spécifier que vous utilisez la bibliothèque Ncurses et pour cela il vous faut rajouter l'option lncurses. 

Exemple gcc -lncurses -o HelloWorld HelloWorld.c
	
En mettant la lettre w devant la plupart des fonctions ---> applique la fonction a la fenetre créée.(en mettant la fenetre en parametre)

 exemple :	refresh();          // actualise/rafraichir la page 
		wrefresh(fenetre);  // actualise/rafraichir la fenetre

	
Quelques fonctions utiles :


 initscr();              // Initialise la structure WINDOW et autres paramètres
 
 noecho();               // evite lors de l'appuie d'une touche sur le clavier, de voir 				     apparaitre la touche sur l'ecran cbreak();

													

 WINDOW * fenetre = newwin(longueur, largeur, x, y);   //Creer une fenetre pour l'input

 box(fenetre, 0, 0);  // Cree un cadre pour la fenetre


 refresh();          // actualise/rafraichir la page 
 wrefresh(fenetre);  // actualise/rafraichir la fenetre

 keypad(fenetre, TRUE); /* pour récupérer les événements du clavier */

 endwin();               // Restaure les paramètres par défaut du terminal
    




