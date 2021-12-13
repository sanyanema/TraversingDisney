EXE = project
TEST = test

EXE_OBJ = main.o
OBJS = main.o src/graph.o src/node.o src/edge.o src/dijkstras.o src/kruskals.o src/BFS.o

include cs225/make/cs225.mk
