#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

int main() {
    long n = 700000000;
    long i, count = 0;
    double x, y, pi;
    double startTime, endTime;
    
    startTime = omp_get_wtime();
    
    srand((unsigned) time(NULL));
    #pragma omp parallel for private(x, y)
    for (i = 0; i < n; i++) {
        x = (double) rand() / RAND_MAX;
        y = (double) rand() / RAND_MAX;

        #pragma omp critical 
        {
        if (x * x + y * y <= 1) count++;
        }
    }

    endTime = omp_get_wtime();

    pi = 4.0 * count / n;
    if(pi<3.14 || 3.15<pi) {
        fprintf(stderr, "Error: estimated value deviates significantly: %f\n");
        return 1;
    }
	printf("%2.4f\n", endTime-startTime);
    return 0;
}
    
    return 0;
}