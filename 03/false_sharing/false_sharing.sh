sbatch ./job.sh
sbatch ./job.sh "perf stat"
sbatch ./job.sh "perf stat -e LLC-load-misses -e LLC-store-misses"
