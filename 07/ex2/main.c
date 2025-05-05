#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <time.h>
#include <omp.h>
#include <stdbool.h>

#ifndef SNIPPET
#define SNIPPET "empty.h"
#endif

void print_array(double* arr, int n) {
	fprintf(stderr, "[ ");
	for(int i=0; i<n; ++i) {
		fprintf(stderr, "%.2f ", *(arr+i));
	}
	fprintf(stderr, "]");
}

void init_array(double* arr, int n) {
	srand(time(NULL));
	for(int i=0; i<n; ++i) {
		arr[i]=(double)rand()/RAND_MAX;
	}
}

int main(int argc, char** argv) {
	if(argc!=2) {
		fprintf(stderr, "Usage: %s <n>\n", *argv);
		return EXIT_FAILURE;
	}

	char* end;
    int n=(int) strtol(*(argv+1), &end, 10);
    if(*end || errno) {
        perror("strtol");
        return EXIT_FAILURE;
    }

	double *x, *y, *z;
	x=malloc(n*sizeof(*x));
	if(!x) {
		perror("malloc");
		return EXIT_FAILURE;
	}
	y=malloc(n*sizeof(*y));
	if(!y) {
		free(x);
		perror("malloc");
		return EXIT_FAILURE;
	}
	z=malloc(n*sizeof(*z));
	if(!z) {
		free(x);
		free(y);
		perror("malloc");
		return EXIT_FAILURE;
	}
	bool twice = true;
	init_array(x, n);
	init_array(y, n);
	init_array(z, n);
	
	double start_time=omp_get_wtime();
	#include SNIPPET
	double end_time=omp_get_wtime();

	// 'surpress' 'variable not used' warnings
	print_array(x, n);
	fprintf(stderr, "\n");
	print_array(y, n);
	fprintf(stderr, "\n");
	print_array(z, n);
	fprintf(stderr, "\n");
	fprintf(stderr, "%d", (int) twice);
	fprintf(stderr, "\n");

	printf("%2.4f\n", end_time-start_time);
	return EXIT_SUCCESS;
}
