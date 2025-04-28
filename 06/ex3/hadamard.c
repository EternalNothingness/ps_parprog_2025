#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <omp.h>
#include <errno.h>

void matrix_init(size_t n, double (*m)[n]) {
    srand(time(NULL));
    for(size_t i=0; i<n; ++i) {
        for(size_t j=0; j<n; ++j) {
            m[i][j]=rand()/RAND_MAX;
        }
    }
}
void hadamard(size_t n, double (*a)[n], double (*b)[n], double (*c)[n]) {
    size_t i, j;
    #pragma omp parallel for schedule(static) private(j)
    for(i=0; i<n; ++i) {
        for(j=0; j<n; ++j) {
            c[i][j]=a[i][j]*b[i][j];
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
    double a[n][n], b[n][n], c[n][n];
    matrix_init(n, a);
    matrix_init(n, b);
    double startTime = omp_get_wtime();
    hadamard(n,a,b,c);
	double endTime = omp_get_wtime();
	printf("%2.4f\n", endTime-startTime);
    return EXIT_SUCCESS;
}
