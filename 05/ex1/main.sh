#!/bin/bash
# Usage: ./main.sh
make
for i in {0..999} 
do
	./ex1
done
make clean
