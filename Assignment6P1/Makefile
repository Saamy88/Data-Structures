a6p1: Assign06P1.o cnPtrQueue.o nodes_LLoLL.o
	g++ Assign06P1.o cnPtrQueue.o nodes_LLoLL.o -o a6p1
Assign06P1.o: Assign06P1.cpp nodes_LLoLL.cpp nodes_LLoLL.h\
              cnPtrQueue.cpp cnPtrQueue.h
	g++ -Wall -ansi -pedantic -c Assign06P1.cpp
cnPtrQueue.o: cnPtrQueue.cpp cnPtrQueue.h  nodes_LLoLL.h
	g++ -Wall -ansi -pedantic -c cnPtrQueue.cpp
nodes_LLoLL.o: nodes_LLoLL.cpp nodes_LLoLL.h
	g++ -Wall -ansi -pedantic -c nodes_LLoLL.cpp
test:
	./a6p1 auto < a6p1_test.in > a6p1_test.out
clean:
	@rm -rf Assign06P1.o cnPtrQueue.o nodes_LLoLL.o
cleanall:
	@rm -rf Assign06P1.o cnPtrQueue.o nodes_LLoLL.o a6p1

