CC=clang
CFLAGS=-g -Wall
BIN=cms

objects := $(wildcard *.o)
sources := $(wildcard *.c)

all: $(BIN)

$(BIN): $(sources)
	$(CC) $(CFLAGS) $^ -o $@

sanitize: $(sources)
	$(CC) $(CFLAGS) $^ -o $@ -fsanitize=address

.PHONY: clean
clean:
	$(RM) -r $(BIN) $(objects) *.dSYM