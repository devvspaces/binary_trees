CC=gcc -Wall -Werror -Wextra -pedantic
TARGET=shell
CFILES=*.c
HFILES=*.h
MAIN=0-main.c

build:
	rm -f main
	$(CC) binary_tree_print.c $(CFILES) tests/$(MAIN)-main.c -o main

test:
	betty $(CFILES) $(HFILES)
	$(CC) -g $(CFILES) -o $(TARGET)

betty:
	betty $(CFILES) $(HFILES)

clean:
	rm -f $(TARGET)