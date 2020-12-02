all: dicionario.o avl.o main.o
	gcc -std=c99 -Wall dicionario.c avl.c main.c -o trab2
	
clean:
	rm *.o trab2
	
run:
	./trab2
