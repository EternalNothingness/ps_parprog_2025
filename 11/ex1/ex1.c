#include <errno.h>
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef SNIPPET
#define SNIPPET "empty.c"
#endif

#define PERROR fprintf(stderr, "%s:%d: error: %s\n", __FILE__, __LINE__, strerror(errno))
#define PERROR_GOTO(label) \
	do { \
		PERROR; \
		goto label; \
	} while (0)

int main(int argc, char **argv) {
	// handle input
	if (argc != 2) {
		fprintf(stderr, "Error: usage: %s <size>\n", argv[0]);
		return EXIT_FAILURE;
	}
	errno = 0;
	char *str = argv[1];
	char *endptr;
	long size = strtol(str, &endptr, 0);
	if (errno != 0) {
		perror("strtol");
		return EXIT_FAILURE;
	}
	if (endptr == str) {
		fprintf(stderr, "Error: no digits were found!\n");
		return EXIT_FAILURE;
	}
	if (size < 0) {
		fprintf(stderr, "Error: array size must not be negative!\n");
		return EXIT_FAILURE;
	}

	// allocate memory
	int status = EXIT_FAILURE;
	float *a = malloc(sizeof(*a) * size);
	if(!a) {
		PERROR_GOTO(error_a);
	}
	float *b = malloc(sizeof(*b) * size);
	if(!b) {
		PERROR_GOTO(error_b);
	}
	float *c = malloc(sizeof(*c) * size);
	if(!c) {
		PERROR_GOTO(error_c);
	}
	status = EXIT_SUCCESS;

	// fill arrays
	srand(7);
	for(long i = 0; i < size; ++i) {
		a[i] = (float) rand()/RAND_MAX;
		b[i] = (float) rand()/RAND_MAX;
		c[i] = (float) rand()/RAND_MAX;
	}

	long repetitions = 1e3;

	double start_time = omp_get_wtime();
#include SNIPPET
	double end_time = omp_get_wtime();
	for(long i=0; i<size; ++i) {
		fprintf(stderr, "a[%ld] = %.3g\n", i, a[i]);
	}
	printf("time: %2.2f seconds\n", end_time - start_time);

	// cleanup
error_c:
	free(c);
error_b:
	free(b);
error_a:
	free(a);
	return status;
}
