CFLAGS = -std=gnu11 -Wall -Werror -Wextra -fopenmp -O3 -lm

.PHONY: all
all: toTable ex1 ex1_fixed

.PHONY: clean
clean:
	$(RM) toTable *.o ex1 ex1_fixed

toTable: toTable.c common.o

common.o: common.c common.h

ex1: ex1.c

ex1_fixed: ex1_fixed.c
