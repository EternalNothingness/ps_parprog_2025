f = 2;
#pragma omp parallel for firstprivate(f) lastprivate(x)
for (i=0; i<N; i++) {
    x = f * b[i];
    a[i] = x - 7;
}
a[0] = x; 
