#ifndef COMMON_H
#define COMMON_H
#include <stdlib.h>

int init_array(void** array, size_t* sizes, size_t n_dim);
double mean(double* values, size_t len);
double sstddev(double mean, double* values, size_t len);
#endif