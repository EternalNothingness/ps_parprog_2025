CC=gcc
CC_FLAGS=-O3 -g3 -lm

.PHONEY: all
all: to_table_row.out serial.out parallel.out

SRC=$(wildcard *.c)

to_table_row.out: to_table_row.o common.o
	$(CC) $(CC_FLAGS) $^ -o $@

to_table_row.o: to_table_row/to_table_row.c to_table_row/common.h
	$(CC) -c $(CC_FLAGS) $< -o $@

common.o: to_table_row/common.c to_table_row/common.h
	$(CC) -c $(CC_FLAGS) $< -o $@

serial.out: $(SRC) serial/serial.c
	@$(CC) $(CC_FLAGS) $(SRC) serial/serial.c -pg -o $@

parallel.out: $(SRC) parallel/parallel.c
	@$(CC) $(CC_FLAGS) $(SRC) parallel/parallel.c -pg -o $@

.PHONEY: clean
clean:
	@rm *.o *.out 

.PHONEY: run
run: all
	@echo "Sequential:"
	@./serial.out
	@echo
