#pragma omp parallel
#pragma omp for
for (i=0; i<N; i++) {
    #pragma omp for
    for (j=0; j<N; j++) {
        a[i][j] = b[i][j];
    }
}
