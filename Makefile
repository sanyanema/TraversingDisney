EXE = proj

# Object Types
# OBJS = edge.o vertex.o graph.o readFromFile.o main.o
OBJS = edge.o graph.o readFromFile.o graphTraversal.o
# OBJS = main.o

# This defines our complier and linker, as we've seen before
CXX = clang++
LD = clang++
CXXFlAGS = -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -Werror -pedantic
LDFLAGS = -std=c++1y -stdlib=libc++ -lc++abi
.PHONY: all test clean output_msg

all : $(EXE)

IS_EWS = $(shell hostname | grep "ews.illinois.edu")
IS_CORRECT_CLANG = $(shell clang -v 2>&1 | grep "version 6")

ifneq ($(strip $(IS_EWS)),)
ifeq ($(strip $(IS_CORRECT_CLANG)),)
CLANG_VERSION_MSG = $(error $(ccred) Run 'module load llvm/6.0.1' on EWS $(ccend)

endif
endif

