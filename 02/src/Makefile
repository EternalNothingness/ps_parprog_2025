OPT = -O0
CFLAGS = -std=gnu11 -Wall -Werror -Wextra -fopenmp $(OPT)

.PHONY: all
all: slow medium fast execall process_data

.PHONY: clean
clean:
	$(RM) slow medium fast execall process_data

slow: slow.c

medium: medium.c

fast: fast.c

execall: execall.c

process_data: process_data.c
