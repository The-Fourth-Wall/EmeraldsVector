NAME = test

CC = clang
OPT = -O2
VERSION = -std=c89
OUTPUT = a.out

FLAGS = -Wall -Wextra -Werror -pedantic -pedantic-errors -Wpedantic
WARNINGS = -Wno-unused-function
HEADERS =
LIBS = ../export/*.so

INPUT = $(NAME).c

all: default

make_library:
	cd .. && em build lib && cd examples

default: make_library
	$(CC) $(OPT) $(VERSION) $(HEADERS) $(FLAGS) $(WARNINGS) $(LIBS) -o $(OUTPUT) $(INPUT)
	./$(OUTPUT)

clean:
	cd .. && em clean && cd examples
	rm -rf $(OUTPUT)
