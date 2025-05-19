CFLAGS = -std=gnu11 -Wall -Werror -Wextra -fopenmp -O3 -lm

.PHONY: all
all: toTable original improved

.PHONY: clean
clean:
	$(RM) toTable *.o original improved

toTable: toTable.c common.o

common.o: common.c common.h

original: ex1.c
	$(CC) $(CFLAGS) -D SNIPPET='"$@.c"' $^ -o $@

improved: ex1.c
	$(CC) $(CFLAGS) -D SNIPPET='"$@.c"' $^ -o $@
