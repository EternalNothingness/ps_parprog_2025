#!/bin/bash
export PROBLEM_SIZE=100000000
export OMP_NUM_THREADS=6
export GOMP_CPU_AFFINITY=0,1,2,3,4,5
echo "running with "$OMP_NUM_THREADS" Threads on cores "$GOMP_CPU_AFFINITY
perf stat -e LLC-load-misses -e LLC-store-misses ./false_sharing $PROBLEM_SIZE
perf stat -e LLC-load-misses -e LLC-store-misses ./false_sharing_2 $PROBLEM_SIZE

export GOMP_CPU_AFFINITY=0,1,2,6,7,8
echo "running with "$OMP_NUM_THREADS" Threads on cores "$GOMP_CPU_AFFINITY
perf stat -e LLC-load-misses -e LLC-store-misses  ./false_sharing $PROBLEM_SIZE
perf stat -e LLC-load-misses -e LLC-store-misses  ./false_sharing_2 $PROBLEM_SIZE
