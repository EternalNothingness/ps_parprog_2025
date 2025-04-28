CFLAGS = -std=gnu11 -Wall -Werror -Wextra -fopenmp -O3 -lm

.PHONY: all
all: mandelbrot toTable

.PHONY: clean
clean:
	$(RM) mandelbrot toTable *.o

mandelbrot: mandelbrot.c

toTable: toTable.c common.o

common.o: common.h
