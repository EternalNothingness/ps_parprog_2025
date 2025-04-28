#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <omp.h>
#include <errno.h>

#ifndef SCHEDULING
    #define SCHEDULING auto
#endif

void matrix_free(size_t n, double **m) {
    for(size_t i=0; i<n; ++i) {
        free(m[i]);
    }
    free(m);
}
double **matrix_init(size_t n) {
    double** m=malloc(n*sizeof(*m));
    if(!m) {
        perror("malloc");
        return NULL;
    }
    srand(time(NULL));
    for(size_t i=0; i<n; ++i) {
        m[i] = malloc(n*sizeof(**m));
        if(!m[i]) {
            matrix_free(i, m);
            perror("malloc");
            return NULL;
        }
        for(size_t j=0; j<n; ++j) {
            m[i][j]=rand()/RAND_MAX;
        }
    }
    return m;
}
void hadamard(size_t n, double **a, double **b, double **c) {
    size_t i, j;
    #pragma omp parallel for schedule(SCHEDULING) private(j)
    for(i=0; i<n; ++i) {
        for(j=0; j<n; ++j) {
            c[i][j] = a[i][j]*b[i][j];
        }
    }
}

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

    double **a=NULL, **b=NULL, **c=NULL;
    a=matrix_init(n);
    if(!a) {
        return EXIT_FAILURE;
    } 
    b=matrix_init(n);
    if(!b) {
        matrix_free(n, a);
        return EXIT_FAILURE;
    }
    c=matrix_init(n);
    if(!c) {
        matrix_free(n, a);
        matrix_free(n, b);
        return EXIT_FAILURE;
    }
    double startTime = omp_get_wtime();
    hadamard(n, a, b, c);
	double endTime = omp_get_wtime();
	printf("%2.4f\n", endTime-startTime);
    matrix_free(n, a);
    matrix_free(n, b);
    matrix_free(n, c);
    return EXIT_SUCCESS;
}
