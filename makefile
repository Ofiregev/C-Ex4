.PHONY== all clean
AR=ar
CC=gcc
FLAGS= -Wall -g

all:libmylib.a graph

graph:main.o libmylib.a
	$(CC) $(FLAGS) -o graph main.o libmylib.a

libmylib.a: nodes.o edges.o algo.o
	$(AR) -rcs libmylib.a nodes.o edges.o algo.o
edges.o:edges.c graph.h
	$(CC) $(FLAGS) -c edges.c graph.h

nodes.o: nodes.c graph.h
	$(CC) $(FLAGS) -c nodes.c graph.h

algo.o: algo.c graph.h
	$(CC) $(FLAGS) -c algo.c graph.h

main.o: main.c graph.h
	$(CC) $(FLAGS) -c main.c

clean:
	rm -f *.o *.a *.so *.out *.gch graph