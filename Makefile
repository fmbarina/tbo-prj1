CC=gcc
CFLAGS=\
	-g \
	-Wall \
	-Wextra \
	-pedantic \
	#-ansi 
LIBS=-lm -I ./headers 

SRC=$(wildcard ./src/*.c)

all: trab1

trab1: $(SRC)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

clean:
	$(RM) ./trab1 ./*.mst ./*.tour

test:
	bash ./utils/test.sh

docs:
	doxygen ./Doxyfile

format:
	clang-format --style=file -i ./src/*.c ./headers/*.h

.PHONY: all clean test docs format
