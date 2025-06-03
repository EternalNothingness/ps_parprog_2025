#!/bin/bash
# Usage: ./benchmark.sh <executable> <number_of_measurements>

results=$1".dat"
echo "x y ey" > $results # create header
make toTable
make $1
export OMP_NUM_THREADS=$(nproc) # set number of threads to the number of processing units available
for i in 100000 500000 1000000 # size of of arrays
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
