#!/bin/bash
# Usage: ./main.sh <executable>

N_SAMPLES=3

make
for i in {1,4,8,12} 
do
	measurements=$i"_"$1".log"
	results=$i"_"$1".tex"
	export OMP_NUM_THREADS=$i
	sbatch --output=$measurements job.sh $1 $N_SAMPLES
	until [ -f $measurements ] # wait until file exists
	do
		sleep 1
	done
	rm $results
	./toTex $measurements $results $N_SAMPLES
	#rm $measurements
done
make clean
