Graph = graph.o
Main = main.o
CC = gcc
AR = ar
FLAGS = -Wall -g

Interface: libgraph.a
libgraph.a: $(Graph)
	$(AR) -rcs -o libgraph.a $(Graph)

main.o: main.c graph.h
	$(CC) $(FLAGS) -c main.c 	

graph: main.o libgraph.a
	$(CC) $(FLAGS) -o graph main.o libgraph.a -lm

all: libgraph.a main.o graph

.PHONY: clean all

clean:
	rm -f *.o *.a *.so libgraph.a main.o graph