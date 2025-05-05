CFLAGS = -std=gnu11 -Wall -Werror -Wextra -fopenmp -O3 -lm -D SNIPPET='"$@.h"'

.PHONY: all
all: toTable a_ser a_par b_ser b_par c_ser c_par

.PHONY: clean
clean:
	$(RM) toTable *.o a_ser a_par b_ser b_par c_ser c_par

toTable: toTable.c common.o

common.o: common.c

a_ser: main.c 

a_par: main.c

b_ser: main.c

b_par: main.c

c_ser: main.c

c_par: main.c

