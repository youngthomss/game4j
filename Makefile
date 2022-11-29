CC=gcc  #compiler
TARGET=jeu #target file name
PATH_CARTE=./game4j/carte/
 
all: jeu clean exec

jeu : jeu.o carte.o section.o 
	$(CC) carte.o section.o jeu.o -o ./bin/$(TARGET)

jeu.o : ./game4j/jeu.c
	$(CC) -c ./game4j/jeu.c -o jeu.o

carte.o : $(PATH_CARTE)carte.c $(PATH_CARTE)carte.h
	$(CC) -c $(PATH_CARTE)carte.c -o carte.o

section.o : $(PATH_CARTE)section.c $(PATH_CARTE)section.h
	$(CC) -c $(PATH_CARTE)section.c -o section.o

clean:
	rm *.o

exec :
	./bin/$(TARGET)