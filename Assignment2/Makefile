a2: IntStore.o Assign02.o
	g++ IntStore.o Assign02.o -o a2
IntStore.o: IntStore.cpp IntStore.h
	g++ -Wall -ansi -pedantic -c IntStore.cpp
Assign02.o: Assign02.cpp IntStore.h
	g++ -Wall -ansi -pedantic -c Assign02.cpp

cleanall:
	@rm a2 *.o
test:
	./a2 auto < a2test.in > a2test.out
nt:
	@rm a2 *.o IntStore.cpp
