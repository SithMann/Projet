CFLAGS = -g -Wall
CC = gcc

all: test_j_VS_j

test_j_VS_j : piece.o grille.o joueur.o test_j_VS_j.o
	$(CC) $^ -o $@ $(CFLAGS) 

%.o:%.c %.h
	$(CC) -c $< $(CFLAGS) 




clean : 
	rm -rf *.o
	rm -rf *.h.gch