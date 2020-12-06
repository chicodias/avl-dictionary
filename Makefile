all: avl.o main.o
	gcc -std=c99 -Wall avl.c main.c -o trab2
	
clean:
	rm *.o trab2
	
run:
	./trab2
