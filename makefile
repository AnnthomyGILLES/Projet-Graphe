CC=gcc

OPT= -Wall -Werror -Wconversion -Wextra -pedantic -std=c99

SRC= main.c  -o main

FCT= graphes-chevauchement

all: 
	$(CC) $(OPT) $(FCT).c $(SRC)



