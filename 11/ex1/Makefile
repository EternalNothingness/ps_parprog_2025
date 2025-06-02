CFLAGS = -std=gnu11 -Wall -Werror -Wextra -fopenmp -O1 -lm

.PHONY: all
all: toTable serial

.PHONY: clean
clean:
	$(RM) toTable *.o serial

toTable: toTable.c common.o

common.o: common.c common.h

serial: ex1.c
	$(CC) $(CFLAGS) -D SNIPPET='"$@.c"' $^ -o $@

