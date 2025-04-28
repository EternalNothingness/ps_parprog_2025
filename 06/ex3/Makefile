OPT = auto
CFLAGS = -std=gnu11 -Wall -Werror -Wextra -fopenmp -O3 -lm -D SCHEDULING=$(OPT)

.PHONY: all
all: hadamard mandelbrot toTable

.PHONY: clean
clean:
	$(RM) hadamard mandelbrot toTable *.o

hadamard: hadamard.c

mandelbrot: mandelbrot.c

toTable: toTable.c common.o

common.o: common.c
