#!/bin/bash
# Usage: ./main.sh
MEASUREMENT_RESULTS=mandelbrot_measurements.log
PROCESSED_RESULTS=mandelbrot_processed.log
make
rm $MEASUREMENT_RESULTS $PROCESSED_RESULTS
for i in {1,2,4,8,12} 
do
	/bin/time -f "%e" -a -o $MEASUREMENT_RESULTS ./mandelbrot $i
done
./toTex $MEASUREMENT_RESULTS $PROCESSED_RESULTS
make clean
