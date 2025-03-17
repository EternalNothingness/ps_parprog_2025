#!/bin/bash
# Usage: ./main.sh [.sh]
rm results_flag_O?.log
for ((i=0;i<=3;++i)); do
	make clean
	make OPT="-O"$i
	for((j=0;j<=2;++j)); do
		echo "flag O"$i", trial "$j
		./execall$1 $(nproc --all) "slow" "medium" "fast" >> "results_flag_O"$i".log"
		echo "" >> "results_flag_O"$i".log" #newline
	done
done
make clean
