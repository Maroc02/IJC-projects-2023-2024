CC=gcc
CFLAGS=-g -std=c11 -pedantic -Wall -Wextra #-Werror
HTAB_HEADER=htab.h htab_private.h
HTAB_LIB=htab_hash_function.o htab_init.o htab_size.o htab_bucket_count.o htab_find.o htab_lookup_add.o htab_erase.o htab_for_each.o htab_clear.o htab_free.o htab_statistics.o
REMOVE=rm -f

# Phony targets
.PHONY: all #clean

# Targets
all: tail wordcount

wordcount: wordcount.o libhtab.a io.o
	$(CC) $(CFLAGS) $^ -o $@

wordcount.o: wordcount.c
	$(CC) $(CFLAGS) -c $< -o $@

io.o: io.c io.h
	$(CC) $(CFLAGS) -c $< -o $@

libhtab.a: $(HTAB_LIB)
	ar crs $@ $^

libhtab.so: $(HTAB_LIB)
	$(CC) $(CFLAGS) -shared -fPIC $^ -o $@

%.o: %.c $(HTAB_HEADER)
	$(CC) $(CFLAGS) -fPIC -c $< -o $@

# IO target
io.o: io.c
	$(CC) $(CFLAGS) -c $< -o $@

# Tail target
tail: tail.o
	 $(CC) $(CFLAGS) $< -o $@

tail.o: tail.c
	 $(CC) $(CFLAGS) -c $< -o $@

#run:
#	 $(CC) $(CFLAGS) $(NAME).c -o $(NAME)

# Clean target
clean:
	 $(REMOVE) *.o
