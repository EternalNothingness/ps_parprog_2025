#pragma omp parallel for lastprivate(a)
for (int i=0; i < n; i++) {
	a = (x[i] + y[i]) / (i+1);
	z[i] = a;
}

f = sqrt(a + k);
