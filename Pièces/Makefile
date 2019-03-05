test_piece : piece.o test_piece.o 
	gcc -g -Wall piece.o test_piece.o -o test_piece
piece.o : piece.c piece.h
	gcc -g -Wall -c piece.c piece.h
test_piece.o : test_piece.c piece.h
	gcc -g -Wall -c test_piece.c piece.h