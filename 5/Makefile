# Makefile for Algorithms
# Joe Smith
# $@ is the name of the rule.

CC = gcc
CFLAGS = -Wall -lm -g
objects = search.o
.PHONY: clean

search:	$(objects)
	$(CC) -o $@ $(CFLAGS) $(objects)

search.o: search.h

clean:
	rm -f search $(objects)
