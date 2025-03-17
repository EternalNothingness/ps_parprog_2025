#!/bin/bash
# Usage: ./main.sh [.sh]
for ((i=0;i<=3;++i)); do
	make clean
	make OPT="-O"$i
	for((j=0;j<=2;++j)); do
		echo "Trial Nr "$j
		./execall$1 $(nproc --all) "slow" "medium" "fast" > "result_flag_O"$i"_trial"$j
	done
done
make clean
