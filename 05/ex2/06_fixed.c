#pragma omp parallel for private(j)
for (i=0; i<N; i++) {
    for (j=0; j<N; j++) {
        a[i][j] = b[i][j];
    }
}
