CFLAGS = -std=gnu11 -Wall -Werror -Wextra -fopenmp -O3 -lm -D SNIPPET='"$@.h"'

.PHONY: all
all: toTable a_ser a_par b_ser b_par c_ser c_par

.PHONY: clean
clean:
	$(RM) toTable *.o *.out

toTable: toTable.o common.o
	$(CC) $(CFLAGS) $^ -o $@

toTable.o: toTable.c common.h
	$(CC) -c $(CFLAGS) $<

common.o: common.c common.h
	$(CC) -c $(CFLAGS) $<

a_ser.out: main.c 

a_par.out: main.c

b_ser.out: main.c

b_par.out: main.c

c_ser.out: main.c

c_par.out: main.c

%.out: main.c
	$(CC) $(CFLAGS) $^ -o $@
