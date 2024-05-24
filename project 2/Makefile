##
# Author: Marek Čupr (xcuprm01)
# College: VUT FIT
# Subject: IJC - Project 2
# Date: 09. 04. 2024
##

# Variables
CC=gcc
CXX=g++
CFLAGS=-g -std=c11 -pedantic -Wall -Wextra # -Werror
CXXFLAGS=-std=c++17 -pedantic -Wall
HTAB_HEADER=htab.h htab_private.h
HTAB_LIB=htab_hash_function.o htab_init.o htab_size.o htab_bucket_count.o htab_find.o htab_lookup_add.o htab_erase.o htab_for_each.o htab_clear.o htab_free.o htab_statistics.o
REMOVE=rm -f

# Phony targets
.PHONY: all wordcount wordcount-dynamic wordcount-statistics wordcount-ref run clean zip

# Targets
all: tail wordcount wordcount-dynamic

# Wordcount targets
wordcount: wordcount.o libhtab.a io.o
	$(CC) $(CFLAGS) $^ -o $@

wordcount-dynamic: wordcount.o libhtab.so io.o
	$(CC) $(CFLAGS) $^ -o $@

wordcount-statistics: wordcount-statistics.o libhtab.a io.o
	$(CC) $(CFLAGS) $^ -o $@

wordcount.o: wordcount.c htab.h io.h
	$(CC) $(CFLAGS) -c $< -o $@

wordcount-statistics.o: wordcount.c htab.h io.h
	$(CC) $(CFLAGS) -DSTATISTICS -c $< -o $@

# Static library
libhtab.a: $(HTAB_LIB)
	ar crs $@ $^

# Dynamic library
libhtab.so: $(HTAB_LIB)
	$(CC) $(CFLAGS) -shared $^ -o $@

# IO target
io.o: io.c io.h
	$(CC) $(CFLAGS) -c $< -o $@

# Htab targets
htab_%.o: htab_%.c $(HTAB_HEADER)
	$(CC) $(CFLAGS) -fPIC -c $< -o $@

# Tail target
tail: tail.o
	 $(CC) $(CFLAGS) $< -o $@

tail.o: tail.c
	 $(CC) $(CFLAGS) -c $< -o $@

# Wordcount reference target
wordcount-: wordcount-.cpp
	$(CXX) $(CXXFLAGS) $< -o $@	 

# Run target
run: tail wordcount-dynamic wordcount wordcount-statistics wordcount-
	seq 1000000 50000 2000000 | shuf | ./tail
	seq 1000000 50000 2000000 | shuf | ./wordcount
	export LD_LIBRARY_PATH="." && seq 1000000 50000 2000000 | shuf | ./wordcount-dynamic
	seq 1000000 50000 2000000 | shuf | ./wordcount-statistics

# Clean target
clean:
	 $(REMOVE) *.o tail wordcount-dynamic wordcount wordcount-statistics wordcount- libhtab.a libhtab.so xcuprm01.zip

# Zip target
zip:
	zip xcuprm01.zip *.c *.h *.cpp Makefile
