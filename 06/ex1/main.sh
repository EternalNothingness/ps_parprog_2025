#!/bin/bash
# Usage: ./main.sh <executable>
N_SAMPLES=3
make
for i in {1,4,8,12} 
do
	export OMP_NUM_THREADS=$i
	sbatch ./job.sh --output=$1".log" $1 $N_SAMPLES
	rm $i"_"$1".tex"
	./toTex $1".log" $i"_"$1".tex" $N_SAMPLES
	rm $1".log"
done
make clean
