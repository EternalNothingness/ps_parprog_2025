#include <common.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

/// @brief initialisizes a n_dim-dimensional array
/// @param arr n_dim-dimensional array to be initialisized
/// @param sizes array, where the n-th value is the size of n-th dimension (e.g. if sizes={2,3}, then arr is initialisized as a matrix with 2 rows and 3 columns)
/// @param n_dim number of dimensions
/// @return 0, if arr was successfully initialisized, -1 otherwise
int init_array(void** arr, size_t* sizes, size_t n_dim) {
    if(n_dim<=0) {
        return EXIT_SUCCESS;
    }
    arr = malloc(*sizes*sizeof(*arr));
    for(size_t i=0; i<*sizes; ++i) {
        if(init_array(*(arr+i), sizes+1, n_dim-1)) {
            for(size_t j=0; j<i; ++j) {
                free(*(arr+j));
            }
            free(arr);
            return -1;
        }
    }
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