#ifndef A_PAR_H
#define A_PAR_H

#pragma omp parallel for schedule(static)
for (int i=0; i < n; i++) {
	x[i] = 1.0/pow(2,i) * y[i];
}
#endif
