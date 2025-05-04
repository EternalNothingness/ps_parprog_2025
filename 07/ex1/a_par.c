#pragma omp parallel for schedule(static)
for (int i=0; i < n-1; i++) {
	x2[i] = (y[i] + x[i+1]) / 7;
}
