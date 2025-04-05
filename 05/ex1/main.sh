#!/bin/bash
# Usage: ./main.sh
MEASUREMENT_RESULTS=measurements
PROCESSED_RESULTS=results
make
for i in {0..999} 
do
	./ex1
done
make clean
