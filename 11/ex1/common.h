#ifndef COMMON_H
#define COMMON_H
#include <stdlib.h>

double mean(double* values, size_t len);
double sstddev(double mean, double* values, size_t len);
void free_2d_array(int **arr, long len);
#endif