#!/bin/bash
# Usage: ./benchmark_matrix_size.sh <executable> <number_of_measurements>

make OPT="static"
export OMP_NUM_THREADS=12
results=$1"_matrix_size.dat"
echo "x y ey" > $results # create header
for i in {10000,20000,30000} # size of matrix
do
	measurements=$i"_"$1".log" 
	for j in $(seq 1 $2) # repeat measurement $2 times
	do
		./$1 $i >> $measurements # store measurement results in <executable>.log
	done
	./toTable $measurements $results $2 $i #store table in <executable>.dat
	rm $measurements
done
make clean
