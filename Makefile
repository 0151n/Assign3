all: main.o poly.o
	gcc main.o poly.o -o poly
main:
	gcc -g -c main.c
poly:
	gcc -g -c poly.c
clean:
	rm *.o poly 
