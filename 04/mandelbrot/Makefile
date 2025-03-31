CFLAGS = -std=gnu11 -Wall -Wextra -lm -lpthread

.PHONY: all
all: mandelbrot toTex 

.PHONY: clean
clean:
	$(RM) mandelbrot mandelbrot.png common.o toTex

mandelbrot: mandelbrot.c

toTex: toTex.c common.o

common.o: common.c
