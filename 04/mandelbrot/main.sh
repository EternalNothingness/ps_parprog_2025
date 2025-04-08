#!/bin/bash
# Usage: ./main.sh
MEASUREMENT_RESULTS=measurements
PROCESSED_RESULTS=results
N_MEASUREMENTS #todo find out how to use shell variables in loop definition
make
for i in {1,2,4,8,12} 
do
	rm $i"_"$MEASUREMENT_RESULTS $i"_"$PROCESSED_RESULTS
	for j in {1..3}
	do
		/bin/time -f "%e" -a -o $i\_$MEASUREMENT_RESULTS ./mandelbrot $i
	done
	./toTex $i\_$MEASUREMENT_RESULTS $i\_$PROCESSED_RESULTS 3
done
make clean
