NAME = test

CC = clang
OPT = -O2
VERSION = -std=c99
OUTPUT = a.out

FLAGS = -Wall -Wextra -Werror -pedantic -pedantic-errors -Wpedantic
WARNINGS = -Wno-unused-function -Wno-strict-prototypes -Wno-int-conversion
HEADERS =
LIBS =

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
