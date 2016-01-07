CC=gcc
SOURCE=magic.c
BIN=magic
FLAGS=$(CFLAGS) -lX11 -lXtst

all:
	$(CC) $(SOURCE) $(FLAGS) -o $(BIN)

clean:
	-@rm -v $(BIN) 2>/dev/null | true
