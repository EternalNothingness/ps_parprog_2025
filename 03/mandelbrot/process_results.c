#include "common.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

#define NUMBER_OF_MEASUREMENTS 3

int main(int argc, char** argv) {
    if(argc!=3) {
        fprintf(stderr, "Usage: ./process_data INPUTFILE OUTPUTFILE\n");
        return EXIT_FAILURE;
    }
    
    FILE* input_file=fopen(*(argv+1), "r");
    if (input_file==NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    double time[NUMBER_OF_MEASUREMENTS];
    for(size_t i=0; i<NUMBER_OF_MEASUREMENTS; ++i) {
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
    // maybe make number of measurements to cmd parameter
    // instead of evaluating all measurments at once, call this program several times in the bash script
    double avg_time=mean(time, NUMBER_OF_MEASUREMENTS);
    fprintf(output_file, "mean=%f, sstdev=%f\n",avg_time, sstddev(avg_time, time, NUMBER_OF_MEASUREMENTS));
    fclose(output_file);
    return EXIT_SUCCESS;
}