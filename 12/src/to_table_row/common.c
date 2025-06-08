#include "common.h"
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <math.h>

// shamelessly stolen from sheet 09
#define PERROR fprintf(stderr, "%s:%d: error: %s\n", __FILE__, __LINE__, strerror(errno))
#define PERROR_GOTO(label) \
	do { \
		PERROR; \
		goto label; \
	} while (0)

#define INIT_ARRAY(arr, label) \
	do { \
		if (!(arr)) PERROR_GOTO(label); \
		for (long i = 0; i < n; ++i) { \
			(arr)[i] = malloc(sizeof(**(arr)) * n); \
			if (!(arr)[i]) PERROR_GOTO(label); \
		} \
	} while (0)

void free_2d_array(int **arr, long len) {
	if (!arr) {
		return;
	}
	for (long i = 0; i < len; ++i) {
		if (!arr[i]) {
			break;
		}
		free(arr[i]);
	}
	free(arr);
}

// computes mean (avg)
double mean(double* values, size_t len) {
    double result=0;
    for(size_t i=0; i<len; result+=*(values+i++));
    return result/len;
}

// computes sample standard deviation
double sstddev(double mean, double* values, size_t len) {
    double result=0;
    for(size_t i=0; i<len; result+=pow((*(values+i++)-mean), 2));
    return sqrt(result/(len-1)); // see definition of *sample* standard deviation 
}
