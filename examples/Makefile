NAME = test

CC = clang
OPT = -O2
VERSION = -std=c99
OUTPUT = a.out

FLAGS = -Wall -Wextra -Werror -pedantic -pedantic-errors -Wpedantic
WARNINGS = -Wno-unused-function -Wno-strict-prototypes
HEADERS =
LIBS = ../export/*.*o

INPUT = $(NAME).c

all: default

make_library:
	cd .. && em build lib release && cd examples

default: make_library
	$(CC) $(OPT) $(VERSION) $(HEADERS) $(FLAGS) $(WARNINGS) $(LIBS) -o $(OUTPUT) $(INPUT)
	./$(OUTPUT)

clean:
	cd .. && em clean && cd examples
	rm -rf $(OUTPUT)
