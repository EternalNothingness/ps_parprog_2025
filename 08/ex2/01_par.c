void copy(double* x, double* y) {
    double* z = malloc(1024*sizeof(*z));
    if(!z) {
	    return;
    }
    #pragma omp parallel for
    for(int i = 0; i < 1024; i++) {
        z[i] = y[i];
    }
    #pragma omp parallel for
    for(int i = 0; i < 1024; i++) {
        x[i] = z[i];
    }
    free(z);
}
