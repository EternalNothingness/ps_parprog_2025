#ifndef A_SER_H
#define A_SER_H

double factor = 1; // S1

for (int i=0; i < n; i++) {
	x[i] = factor * y[i]; // S2
	factor = factor / 2; // S3
}
#endif
