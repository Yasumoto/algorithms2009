# Makefile for Algorithms
# Joe Smith
# $@ is the name of the rule.

CC = gcc
CFLAGS = -Wall -lm
objects = search.o queue.o
.PHONY: clean

search:	$(objects)
	$(CC) -o $@ $(CFLAGS) $(objects)

search.o: search.h

queue.o: search.h

clean:
	rm -f search $(objects)
