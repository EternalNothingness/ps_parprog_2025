#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>
#define _USE_MATH_DEFINES
#include <math.h>


int main() {
    long n = 700000000;
    long i, count = 0;
    double x, y, pi;
    double startTime, endTime;
    
    startTime = omp_get_wtime();
    
    #pragma omp parallel private(x, y)
    {
        unsigned seed = (unsigned) time(NULL)+13*omp_get_thread_num();
        #pragma omp for schedule (static)
        for (i = 0; i < n; i++) {
            x = (double) rand_r(&seed) / RAND_MAX;
            y = (double) rand_r(&seed) / RAND_MAX;

            #pragma omp critical 
            {
                if (x * x + y * y <= 1) count++;
            }
        }
    }

    endTime = omp_get_wtime();

    pi = 4.0 * count / n;

    if(pi<0.99*M_PI|| 1.01*M_PI<pi) {
        fprintf(stderr, "Error: estimated value deviates significantly: %f\n", pi);
        return 1;
    }
	printf("%2.4f\n", endTime-startTime);
    return 0;
}