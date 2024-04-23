NAME = Vector

CC = clang
DEBUG_OPT = -Og -g
DEBUG_VERSION = -std=c89
DEBUG_FLAGS = -Wall -Wextra -Werror -pedantic -pedantic-errors -Wpedantic

RELEASE_OPT = -O2
RELEASE_VERSION = -std=c11
RELEASE_FLAGS = 

WARNINGS = -Wno-incompatible-pointer-types
UNUSED_WARNINGS = -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -Wno-extra-semi
REMOVE_WARNINGS = -Wno-int-conversion
TEST_WARNINGS = -Wno-implicit-function-declaration -Wno-incompatible-pointer-types
LIBS = -c
DEPS = $(shell find ./export -name "*.*o" 2>&1 | grep -v "No such file or directory")

INPUTFILES = $(shell find src/Vector/*.c 2>&1 | grep -v "No such file or directory")
INPUT = $(shell find src/Vector.c 2>&1 | grep -v "No such file or directory")
OUTPUT = Vector

TESTINPUT = $(shell find spec/Vector.spec.c 2>&1 | grep -v "No such file or directory")
TESTOUTPUT = spec_results

all: app_debug

make_export:
	$(RM) -r export && mkdir export

copy_headers:
	mkdir export/$(NAME) && mkdir export/$(NAME)/headers
	cp -r src/$(NAME)/headers/* export/$(NAME)/headers/ >/dev/null 2>&1 || true
	cp src/$(NAME).h export/ >/dev/null 2>&1 || true

app_debug: make_export
	$(CC) $(DEBUG_OPT) $(DEBUG_VERSION) $(DEBUG_FLAGS) $(WARNINGS) $(REMOVE_WARNINGS) $(UNUSED_WARNINGS) -o $(OUTPUT) $(INPUT) $(INPUTFILES) $(DEPS)
	mv $(OUTPUT) export/ >/dev/null 2>&1 || true

app_release: make_export
	$(CC) $(RELEASE_OPT) $(RELEASE_VERSION) $(RELEASE_FLAGS) -o $(OUTPUT) $(INPUT) $(INPUTFILES) $(DEPS)
	mv $(OUTPUT) export/ >/dev/null 2>&1 || true

lib_debug: make_export copy_headers
	$(CC) $(DEBUG_OPT) $(DEBUG_VERSION) $(DEBUG_FLAGS) $(WARNINGS) $(REMOVE_WARNINGS) $(UNUSED_WARNINGS) $(LIBS) $(INPUTFILES)
	mv *.o export/ >/dev/null 2>&1 || true
	mv $(shell find ./libs -name "*.*o") export/ >/dev/null 2>&1 || true

lib_release: make_export copy_headers
	$(CC) $(RELEASE_OPT) $(RELEASE_VERSION) $(RELEASE_FLAGS) $(LIBS) $(INPUTFILES)
	mv *.o export/ >/dev/null 2>&1 || true
	mv $(shell find ./libs -name "*.*o") export/ >/dev/null 2>&1 || true

test: lib_release
	$(CC) $(RELEASE_OPT) $(RELEASE_VERSION) $(RELEASE_FLAGS) $(TEST_WARNINGS) -o spec/$(TESTOUTPUT) $(DEPS) $(TESTINPUT)
	@echo
	./spec/$(TESTOUTPUT)

spec: test

clean:
	$(RM) -r spec/$(TESTOUTPUT)
	$(RM) -r export *.dSYM

