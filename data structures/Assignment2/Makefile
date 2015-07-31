a2: SortedInt2.o Assign02.o
	g++ SortedInt2.o Assign02.o -o a2
SortedInt2.o: SortedInt2.cpp SortedInt2.h
	g++ -Wall -ansi -pedantic -c SortedInt2.cpp
Assign02.o: Assign02.cpp SortedInt2.h
	g++ -Wall -ansi -pedantic -c Assign02.cpp

clean:
	@rm -rf SortedInt2.o Assign02.o
cleanall:
	@rm -rf SortedInt2.o Assign02.o a2

test :
	./a2 auto < a2test.in > a2test.out
nt :
	@rm -rf a2 *.o *.out SortedInt2.cpp
	
