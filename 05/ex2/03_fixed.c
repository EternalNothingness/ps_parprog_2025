#pragma omp parallel for default(none) private(i, x) shared(a, b) ordered
for (i=0; i<N; i++) {
    #pragma ordered {
        x = sqrt(b[i]) - 1;
    }
    a[i] = x*x + 2*x + 1;
}
