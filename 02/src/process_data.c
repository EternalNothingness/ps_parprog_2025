#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) {
   if(argc!=2) {
        fprintf(stderr, "Usage: ./process_data INPUTFILE\n");
        return EXIT_FAILURE;
    }
    
    FILE* input_file= fopen(*(argv+1), "r");
    if (input_file==NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    int opm_num_threads;
    char program[64];
    long  long sum;
    double time;
    enum speed {SLOW, MEDIUM, FAST, NSPEED};
    int nproc = 4;
    double avg_time[nproc][NSPEED];

    while (fscanf(input_file, "OMP_NUM_THREADS: %d, executing: %63[^,], sum: %lld, time: %lf seconds\n", &opm_num_threads, program, &sum, &time) != EOF) {
        //printf("OMP_NUM_THREADS: %d, executing: %s, sum: %lld, time: %f seconds\n", opm_num_threads, program, sum, time);
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