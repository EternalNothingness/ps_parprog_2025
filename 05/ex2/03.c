#pragma omp parallel for default(none)
for (i=0; i<N; i++) {
    x = sqrt(b[i]) - 1;
    a[i] = x*x + 2*x + 1;
}
