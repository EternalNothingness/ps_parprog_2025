#!/bin/bash
# Usage: ./benchmark.sh <executable> <number_of_measurements>

results=$1".dat"
echo "x y ey" > $results # create header
make
for i in {1,4,8,12} # number of threads
do
	measurements=$i"_"$1".log" 
	export OMP_NUM_THREADS=$i
	for j in $(seq 1 $2) # repeat measurement $2 times
	do
		./$1 >> $measurements # store measurement results in <executable>.log
	done
	./toTable $measurements $results $2 $i #store table in <executable>.dat
	rm $measurements
done
make clean
