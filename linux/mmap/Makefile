all: test1.o test2.o test3.o

test1.o: MAP_SHARED.cpp
	gcc -c MAP_SHARED.cpp -o test1.0

test2.o: MAP_SHARED1.cpp
	gcc -c MAP_SHARED1.cpp -o test2.o

test3.o: MAP_ANONYMOUS.cpp
	gcc -c MAP_ANONYMOUS.cpp -o test3.0

clean:
	rm -rf *.o
