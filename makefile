all: main.o
	gcc -o randfile main.o

main.o: main.c
	gcc -c main.c

run:
	./randfile

clean:
	rm randfile
	rm numbers.txt
	rm *.o
