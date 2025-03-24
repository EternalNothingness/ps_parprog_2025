#!/bin/bash
# Usage: ./main.sh
make
rm results_mandelbrot.log
for ((i=0;i<=2;++i)); do
	/bin/time -a -o "results_mandelbrot.log" ./mandelbrot
done
make clean
