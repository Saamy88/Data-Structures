a1: SortedInt.o Assign01.o
	g++ SortedInt.o Assign01.o -o a1
SortedInt.o: SortedInt.cpp SortedInt.h
	g++ -Wall -ansi -pedantic -c SortedInt.cpp
Assign01.o: Assign01.cpp SortedInt.h
	g++ -Wall -ansi -pedantic -c Assign01.cpp

test:
	./a1 auto < a1test.in > a1test.out
clean:
	@rm -rf SortedInt.o Assign01.o
cleanall:
	@rm -rf SortedInt.o Assign01.o a1


