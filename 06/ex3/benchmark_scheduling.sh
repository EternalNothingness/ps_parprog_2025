#!/bin/bash
# Usage: ./benchmark_scheduling.sh <executable> <number_of_measurements>

export OMP_NUM_THREADS=4
dim=10
results=$1"_scheduling.dat"
echo "x y ey" > $results # create header
for i in {"static","dynamic","guided","auto","runtime"} # loop scheduling method
do
	make OPT=$i
	measurements=$i"_"$1".log" 
	for j in $(seq 1 $2) # repeat measurement $2 times
	do
		./$1 $dim >> $measurements # store measurement results in <executable>.log
	done
	./toTable $measurements $results $2 $i #store table in <executable>.dat
	rm $measurements
	make clean
done
