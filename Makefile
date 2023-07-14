# Set compiler
CC=clang
# Set compiler flags (should be valid for clang and gcc)
CFLAGS=-g -Wall -lm -Isrc
# Binary executable name
BIN=cms

# Set source global extension (depending on being C or C++ source files)
SRC_EXTENSION = c

# Link source files as wildcard
sources := $(wildcard *.$(SRC_EXTENSION)) $(wildcard */*.$(SRC_EXTENSION))

.PHONY: all clean

DEBUG_PATH = ./bin/debug
RELEASE_PATH = ./bin/release

all: debug

before-debug:
	@echo "Making debug directory binaries if not exist"
	mkdir -p $(DEBUG_PATH)

before-release:
	@echo "Making release directory binaries if not exist"
	mkdir -p $(RELEASE_PATH)

release: before-release
	$(CC) $(CFLAGS) -O1 $(sources) -o $(RELEASE_PATH)/$(BIN)

debug: before-debug
	$(CC) $(CFLAGS) $(sources) -o $(DEBUG_PATH)/$(BIN)

sanitize: before-debug
	$(CC) $(CFLAGS) $(sources) -o $(DEBUG_PATH)/$(BIN) -fsanitize=address


clean:
	$(RM) -r $(BIN) *.dSYM