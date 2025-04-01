#include "common.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

int main(int argc, char** argv) {
    if(argc!=4) {
        fprintf(stderr, "Usage: %s INPUTFILE OUTPUTFILE N_MEASUREMENTS\n", *argv);
        return EXIT_FAILURE;
    }
    
    FILE* input_file=fopen(*(argv+1), "r");
    if (input_file==NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    char* end;
    long n_measurements=strtol(*(argv+3), &end, 10);
    if(*end || errno) {
        perror("strtol");
        return EXIT_FAILURE;
    }
    double time[n_measurements];
    for(long i=0; i<n_measurements; ++i) {
        fscanf(input_file, "%lf\n", time+i);
        if(errno) {
            perror("fscanf");
            return EXIT_FAILURE;
        }
    }
    fclose(input_file);
    
    FILE* output_file=fopen(*(argv+2), "w");
    if (output_file==NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }
    //TODO Rename file to toTex.c, print output to latex-file
    // instead of evaluating all measurments at once, call this program several times in the bash script
    double avg_time=mean(time, n_measurements);
    fprintf(output_file, "mean,\tsstdev\n%f,\t%f", avg_time, sstddev(avg_time, time, n_measurements));
    fclose(output_file);
    return EXIT_SUCCESS;
}