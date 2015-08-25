prog4: list.o graph.o main.o
	g++ list.o graph.o main.o -o prog4
list.o: linkedList.h list.cc
	g++ -c -g -Wall list.cc
graph.o: graph.h graph.cc
	g++ -c -g graph.cc
main.o: main.cc
	g++ -c -g main.cc
