#!/bin/bash
# Usage: ./main.sh <executable> <number_of_measurements>

make
for i in {1,4,8,12} 
do
	measurements=$i"_"$1".log"
	results=$i"_"$1".tex"
	export OMP_NUM_THREADS=$i
	for i in $(seq 1 $2)
	do
		./$1 >> $measurements
	done
	rm $results
	./toTex $measurements $results $2
	rm $measurements
done
make clean
