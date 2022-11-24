CC=gcc  #compiler
TARGET=banque #target file name
 
all: jeu clean exec

jeu : main.o compte.o client.o
	$(CC) main.o compte.o client.o -o $(TARGET)

main.o : main.c
	$(CC) -c main.c -o main.o

compte.o : compte.c compte.h
	$(CC) -c compte.c -o compte.o

client.o : client.c client.h
	$(CC) -c client.c -o client.o

clean:
	rm *.o

exec :
	./$(TARGET)