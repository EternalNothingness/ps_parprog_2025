CFLAGS = -std=gnu11 -Wall -Werror -Wextra -fopenmp

.PHONY: all
all: slow medium fast execall

.PHONY: clean
clean:
	$(RM) slow medium fast execall

slow: slow.c

medium: medium.c

fast: fast.c

execall: execall.c
