a3: sequence.o assign03.o
	g++ sequence.o assign03.o -o a3
sequence.o: sequence.cpp sequence.h
	g++ -Wall -ansi -pedantic -c sequence.cpp
assign03.o: assign03.cpp sequence.cpp sequence.h
	g++ -Wall -ansi -pedantic -c assign03.cpp

clean:
	@rm -rf sequence.o assign03.o
cleanall:
	@rm -rf sequence.o assign03.o a3

