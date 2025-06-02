CFLAGS = -std=gnu11 -Wall -Werror -Wextra -fopenmp -O1 -lm

.PHONY: all
all: toTable serial serial_vectorized

.PHONY: clean
clean:
	$(RM) toTable *.o serial serial_vectorized

toTable: toTable.c common.o

common.o: common.c common.h

serial: ex1.c
	$(CC) $(CFLAGS) -D SNIPPET='"serial.c"' $^ -o $@

serial_vectorized: ex1.c
	$(CC) $(CFLAGS) -ftree-vectorize -fopt-info-vec-optimized-missed -D SNIPPET='"serial.c"' $^ -o $@
