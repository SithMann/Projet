CC=gcc
FLAGS = -Wall -g

SDL_DIR=${HOME}/SDL2
SDLLIB_DIR=${SDL_DIR}/lib
SDLINC_DIR=${SDL_DIR}/include

LIBS=-L${SDLLIB_DIR} -lSDL2 -lSDL2_ttf -lSDL2_image
INCLUDES=-I${SDLINC_DIR} 

PROG=test_sdl

all: test_sdl

test_sdl: test_sdl.c
	${CC} $^ -o $@ ${LIBS} ${INCLUDES} ${FLAGS}

clean: 
	rm -f ${PROG}
	rm -f *.o