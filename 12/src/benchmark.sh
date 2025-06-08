#!/bin/bash
# Usage: ./benchmark.sh <executable> <number_of_measurements>

results=$1".dat"
echo "x y ey" > $results # create header
make to_table_row
make $1
for i in 1 2 6 12 # number of threads
do
    export OMP_NUM_THREADS=$i
	measurements=$i"_"$1".log" 
	for j in $(seq 1 $2) # repeat measurement $2 times
	do
		./$1 >> $measurements # store measurement results in <executable>.log
	done
	./to_table_row_row $measurements $results $2 $i #store table row in <executable>.dat
	rm $measurements
done
make clean
