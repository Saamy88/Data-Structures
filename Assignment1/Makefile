a1: IntStore.o Assign01.o
	g++ IntStore.o Assign01.o -o a1
IntStore.o: IntStore.cpp IntStore.h
	g++ -Wall -ansi -pedantic -c IntStore.cpp
Assign01.o: Assign01.cpp IntStore.h
	g++ -Wall -ansi -pedantic -c Assign01.cpp

cleanall:
	@rm a1 *.o
test:
	./a1 auto < a1test.in > a1test.out
