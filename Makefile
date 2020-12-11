all: item.o avl.o heap.o main.o
	gcc -std=c99 -g -Wall item.c heap.c avl.c main.c -o trab2
	
clean:
	rm *.o trab2
	
run:
	./trab2 <casos_teste/3.in
