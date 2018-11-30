objects = main.o poly.o

all: $(objects)
	gcc main.o poly.o -o poly
	./poly
main:
	gcc -g -c main.c
poly:
	gcc -g -c poly.c
clean:
	rm *.o poly
       	
