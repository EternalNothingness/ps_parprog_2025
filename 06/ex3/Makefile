CFLAGS = -std=gnu11 -Wall -Werror -Wextra -fopenmp -O3 -lm

.PHONY: all
all: hadamard toTable

.PHONY: clean
clean:
	$(RM) hadamard toTable *.o

hadamard: hadamard.c

toTable: toTable.c common.o

common.o: common.c
