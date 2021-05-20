CC=gcc
CFLAGS= -Wall -ansi -pedantic
EXEC=prog

all: $(EXEC)

prog: piece.o tablier.o coordonnee.o liste_double.o partie.o  main.o
	$(CC) -o prog piece.o tablier.o coordonnee.o liste_double.o partie.o  main.o

piece.o: piece.c
	$(CC) -o piece.o -c piece.c $(CFLAGS)

tablier.o: tablier.c
	$(CC) -o tablier.o -c tablier.c $(CFLAGS)

coordonnee.o: coordonnee.c
	$(CC) -o coordonnee.o -c coordonnee.c $(CFLAGS)


liste_double.o: liste_double.c
	$(CC) -o liste_double.o -c liste_double.c $(CFLAGS)


partie.o: partie.c
	$(CC) -o partie.o -c partie.c $(CFLAGS)


main.o: main.c
	$(CC) -o main.o -c main.c $(CFLAGS)

clean:
	rm -rf *.o
