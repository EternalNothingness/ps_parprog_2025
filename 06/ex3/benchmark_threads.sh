#!/bin/bash
# Usage: ./benchmark_threads.sh <executable> <number_of_measurements>

make OPT="dynamic"
dim=10000
results=$1"_threads.dat"
echo "x y ey" > $results # create header
for i in {1,4,8,12} # number of threads
do
	measurements=$i"_"$1".log" 
	export OMP_NUM_THREADS=$i
	for j in $(seq 1 $2) # repeat measurement $2 times
	do
		./$1 $dim >> $measurements # store measurement results in <executable>.log
	done
	./toTable $measurements $results $2 $i #store table in <executable>.dat
	rm $measurements
done
make clean
