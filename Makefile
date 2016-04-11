### Makefile ###

all: Atividade4

Atividade4: Atividade4.c
	gcc -DDEBUG -g Atividade4.c -o Atividade4

run: Atividade4
	./Atividade4
