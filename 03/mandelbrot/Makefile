CFLAGS = -std=gnu11 -Wall -Wextra -lm

.PHONY: all
all: mandelbrot process_results

.PHONY: clean
clean:
	$(RM) mandelbrot mandelbrot.png common.o process_results

mandelbrot: mandelbrot.c

process_results: process_results.c common.o

common.o: common.c
