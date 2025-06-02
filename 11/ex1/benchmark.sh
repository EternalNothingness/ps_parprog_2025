#!/bin/bash
# Usage: ./benchmark.sh <executable> <number_of_measurements>

N=# size of arrays
results=$1".dat"
echo "x y ey" > $results # create header
make toTable
make $1
for i in {100000, 5000000, 1000000} # size of of arrays
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
