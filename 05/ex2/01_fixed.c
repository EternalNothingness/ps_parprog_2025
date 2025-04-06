a[0] = 0;
#pragma omp parallel for ordered
for (i=1; i<N; i++) {
    a[i] = 2.0*i*(i-1);
    #pragma omp ordered {
    b[i] = a[i] - a[i-1];
    }
}
