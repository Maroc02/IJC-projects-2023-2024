##
# Author: Marek Čupr (xcuprm01)
# College: VUT FIT
# Subject: IJC - Project 1
# Date: 23. 02. 2024
##

# Variables
CC=gcc
CFLAGS=-std=c11 -pedantic -Wall -Wextra -g
LDFLAGS=-lm
OPT=-O2

# Phony targets
.PHONY: all run clean zip

# Targets
all: primes primes-i no-comment

# Primes target
primes: primes.o eratosthenes.o bitset.o error.o
	$(CC) $(CFLAGS) $(OPT) $(LDFLAGS) $^ -o $@

primes.o: primes.c eratosthenes.h bitset.h
	$(CC) $(CFLAGS) $(OPT) $(LDFLAGS) -c $< -o $@

# Primes inline target
primes-i: primes-i.o eratosthenes-i.o bitset-i.o error.o
	$(CC) $(CFLAGS) $(OPT) $(LDFLAGS) -DUSE_INLINE $^ -o $@

primes-i.o: primes.c eratosthenes.h bitset.h
	$(CC) $(CFLAGS) $(OPT) $(LDFLAGS) -DUSE_INLINE -c $< -o $@

# Eratosthenes target
eratosthenes.o: eratosthenes.c eratosthenes.h bitset.h
	$(CC) $(CFLAGS) $(OPT) $(LDFLAGS) -c $< -o $@

# Eratosthenes inline target
eratosthenes-i.o: eratosthenes.c eratosthenes.h bitset.h
	$(CC) $(CFLAGS) $(OPT) $(LDFLAGS) -DUSE_INLINE -c $< -o $@

# Bitset target
bitset.o: bitset.c bitset.h error.h
	$(CC) $(CFLAGS) $(OPT) -c $< -o $@

# Bitset inline target
bitset-i.o: bitset.c bitset.h error.h
	$(CC) $(CFLAGS) $(OPT) -DUSE_INLINE -c $< -o $@

# No comment target
no-comment: no-comment.o error.o
	$(CC) $(CFLAGS) $(OPT) $^ -o $@

no-comment.o: no-comment.c no-comment.h error.h
	$(CC) $(CFLAGS) $(OPT) -c $< -o $@

# Error target
error.o: error.c error.h 
	$(CC) $(CFLAGS) $(OPT) -c $< -o $@

# Run target
run: primes primes-i no-comment
	ulimit -s 82000 && ./primes && ./primes-i

# Clean target
clean:
	rm -f *.o primes primes-i no-comment xcuprm01.zip

# Zip target
zip:
	zip xcuprm01.zip *.c *.h Makefile