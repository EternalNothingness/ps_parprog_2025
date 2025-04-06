sum = 0; 
#pragma omp parallel for reduction(+: sum)
for (i=0; i<N; i++) {
    sum = sum + b[i];
}
