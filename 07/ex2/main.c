#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <time.h>
#include <omp.h>

#ifndef SNIPPET
#define SNIPPET "a_ser.h"
#endif

int main(int argc, char** argv) {
	if(argc!=2) {
		fprintf(stderr, "Usage: %s <n>\n", *argv);
		return EXIT_FAILURE;
	}

	char* end;
    size_t n=(size_t) strtoll(*(argv+1), &end, 10);
    if(*end || errno) {
        perror("strtol");
        return EXIT_FAILURE;
    }

	double start_time=omp_get_wtime();
	#include SNIPPET
	double end_time=omp_get_wtime();
	printf("%2.4f\n", end_time-start_time);
	return EXIT_SUCCESS;
}
