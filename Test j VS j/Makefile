test_j_VS_j : piece.o grille.o joueur.o test_j_VS_j.o
	gcc -g -Wall piece.o grille.o joueur.o test_j_VS_j.o -o test_j_VS_j
joueur.o : joueur.c joueur.h
	gcc -g -Wall -c joueur.c joueur.h
piece.o : piece.c piece.h
	gcc -g -Wall -c piece.c piece.h
grille.o : grille.c grille.h
	gcc -g -Wall -c grille.c grille.h
test_j_VS_j.o : test_j_VS_j.c grille.h
	gcc -g -Wall -c test_j_VS_j.c grille.h