#!/bin/bash
# Usage: ./main.sh
MEASUREMENT_RESULTS=mandelbrot_measurements.log
PROCESSED_RESULTS=mandelbrot_processed.log
make
rm $MEASUREMENT_RESULTS $PROCESSED_RESULTS
for ((i=0;i<=2;++i)); do
	/bin/time -f "%e" -a -o $MEASUREMENT_RESULTS ./mandelbrot
done
./process_results $MEASUREMENT_RESULTS $PROCESSED_RESULTS
make clean
