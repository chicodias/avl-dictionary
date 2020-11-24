all: abb.o main.o
	gcc -std=c99 -Wall abb.c main.c -o ex7
	
clean:
	rm *.o ex7
	
run:
	./ex7
