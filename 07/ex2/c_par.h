#ifndef C_PAR_H
#define C_PAR_H

x[0] = x[0] + 5 * y[0];
#pragma omp parallel for schedule(static)
for (int i = 1; i<n; i++) {
	x[i] = x[i] + 5 * y[i];
}

if (twice ) {
	#pragma omp parallel for schedule(static)
	for (int i = 1; i<n; i++) {
		x[i-1] = 2 * x[i-1];
	}
}
#endif
