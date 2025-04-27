#!/bin/bash
# Usage: ./main.sh <executable> <number_of_measurements>

results=$1".dat"
echo "x y ey" > $results
make
for i in {1,4,8,12} 
do
	measurements=$i"_"$1".log"
	export OMP_NUM_THREADS=$i
	for j in $(seq 1 $2)
	do
		./$1 >> $measurements
	done
	./toTable $measurements $results $2 $i
	rm $measurements
done
make clean
