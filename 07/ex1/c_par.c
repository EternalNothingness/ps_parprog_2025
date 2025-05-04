#pragma omp parallel for schedule(static)
for (int i=0; i < n; i++) {
	x[i] = y[i] * 2 + b * i;
}

#pragma omp parallel for schedule(static)
for (int i=0; i < n; i++) {
	y[i] = x[i] + a / (i+1);
}
