#ifndef B_PAR_H
#define B_PAR_H

#pragma omp parallel for schedule(static)
for (int i=1; i<n; i++) {
	y[i] = y[i] +z[i] * 3;
}

#pragma omp parallel for schedule(static)
for (int i=1; i<n; i++) {
	x[i] = (x[i] + y[i-1]) / 2;
}
#endif
