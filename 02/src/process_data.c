#include "common.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

int main(int argc, char** argv) {
   if(argc!=3) {
        fprintf(stderr, "Usage: ./process_data INPUTFILE OUTPUTFILE\n");
        return EXIT_FAILURE;
    }
    
    FILE* input_file= fopen(*(argv+1), "r");
    if (input_file==NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    enum speed {SLOW, MEDIUM, FAST, NSPEED};
    int opm_num_threads;
    char program[64];
    double time;
    int nproc = 4;
    double avg_time[nproc][NSPEED];
    double*** time_points;

    while (fscanf(input_file, "OMP_NUM_THREADS: %d, executing: %63[^,], sum: %*lld, time: %lf seconds\n", &opm_num_threads, program, &time) != EOF) {
        if(errno) {
            perror("fscanf");
            return EXIT_FAILURE;
        }
        if(!strcmp(program, "slow")) {
            avg_time[opm_num_threads-1][SLOW]+= time;
        } else if(!strcmp(program, "medium")) {
            avg_time[opm_num_threads-1][MEDIUM] += time;
        } else {
            avg_time[opm_num_threads-1][FAST] += time;
        }
    }
    
    for(size_t i=0; i<(size_t)nproc; ++i) {
        for(size_t j=0; j<(size_t)NSPEED; ++j) {
            avg_time[i][j]/=3;
            printf("avg_time[%zu][%zu]=%f\n",i, j, avg_time[i][j]);
        }
    }
    fclose(input_file);
    return EXIT_SUCCESS;
}