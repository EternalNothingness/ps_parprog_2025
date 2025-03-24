#!/bin/bash
export PROBLEM_SIZE=10 #100000000
export OMP_NUM_THREADS=6
export GOMP_CPU_AFFINITY=0,1,2,3,4,5
echo "running with "$OMP_NUM_THREADS" Threads on cores "$GOMP_CPU_AFFINITY"\n"
./false_sharing 10 $PROBLEM_SIZE
./false_sharing_2 10 $PROBLEM_SIZE

export GOMP_CPU_AFFINITY=0,1,2,6,7,8
echo "running with "$OMP_NUM_THREADS" Threads on cores "$GOMP_CPU_AFFINITY"\n"
./false_sharing 10 $PROBLEM_SIZE
./false_sharing_2 10 $PROBLEM_SIZE
