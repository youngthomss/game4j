CC=gcc  #compiler
TARGET=jeu #target file name
PATH_CARTE=./game4j/carte/
PATH_ALGORITHME=./game4j/algorithme/

 
all: jeu clean exec

jeu : jeu.o carte.o section.o generation.o arbre.o
	$(CC) carte.o section.o jeu.o generation.o arbre.o -o $(TARGET)

jeu.o : ./game4j/jeu.c
	$(CC) -c ./game4j/jeu.c -o jeu.o

carte.o : $(PATH_CARTE)carte.c $(PATH_CARTE)carte.h
	$(CC) -c $(PATH_CARTE)carte.c -o carte.o

section.o : $(PATH_CARTE)section.c $(PATH_CARTE)section.h
	$(CC) -c $(PATH_CARTE)section.c -o section.o

arbre.o : $(PATH_CARTE)arbre.c $(PATH_CARTE)arbre.h
	$(CC) -c $(PATH_CARTE)arbre.c -o arbre.o

generation.o : $(PATH_ALGORITHME)generation.c $(PATH_ALGORITHME)generation.h
	$(CC) -c $(PATH_ALGORITHME)generation.c -o generation.o

djikstra.o : $(PATH_ALGORITHME)djikstra.c $(PATH_ALGORITHME)djikstra.h
	$(CC) -c $(PATH_ALGORITHME)djikstra.c -o djikstra.o

clean:
	rm *.o

exec :
	./$(TARGET)