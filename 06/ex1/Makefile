CFLAGS = -std=gnu11 -Wall -Werror -Wextra -fopenmp -O3 -lm

.PHONY: all
all: serial atomic critical reduction toTable

.PHONY: clean
clean:
	$(RM) serial atomic critical reduction common.o toTable

serial: serial.c

atomic: atomic.c

critical: critical.c

reduction: reduction.c

toTable: toTable.c common.o

common.o: common.c
