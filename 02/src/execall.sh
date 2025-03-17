#!/bin/bash
declare NPROC=$1
shift
for((i=1;i<=NPROC;++i)); do
	export OMP_NUM_THREADS=$i
	#echo "OMP_NUM_THREADS="$OMP_NUM_THREADS
	for var in "$@"
	do
		echo "OMP_NUM_THREADS: "$OMP_NUM_THREADS", executing: "$var $(./$var)
	done
done
