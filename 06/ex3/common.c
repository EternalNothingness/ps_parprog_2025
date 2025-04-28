#include "common.h"
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <math.h>

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
