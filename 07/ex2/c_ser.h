#ifndef B_SER_H
#define B_SER_H

x[0] = x[0] + 5 * y[0]; // S1
for (int i = 1; i<n; i++) {
	x[i] = x[i] + 5 * y[i]; // S2
	if ( twice /* S3 */) {
		x[i-1] = 2 * x[i-1]; // S4
	}
}
#endif
