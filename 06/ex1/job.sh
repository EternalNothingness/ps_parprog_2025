#!/bin/bash
# usage: sbatch [slurm_options] job.sh <executable> <number_of_executions>

# Execute job in the partition "lva" unless you have special requirements.
#SBATCH --partition=lva
# Name your job to be able to identify it later
#SBATCH --job-name csba4017
# Redirect output stream to this file
#SBATCH --output=output.log
# Maximum number of tasks (=processes) to start in total
#SBATCH --ntasks=1
# Maximum number of tasks (=processes) to start per node
#SBATCH --ntasks-per-node=1
# Enforce exclusive node allocation, do not share with other jobs
#SBATCH --exclusive
# Enable hyperthreading
#SBATCH --hint=multithread

for i in $(seq 1 $2)
do
	./$1
done
