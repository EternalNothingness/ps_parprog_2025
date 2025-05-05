#ifndef A_PAR_H
#define A_PAR_H

double *factor = malloc(n*sizeof(*factor));
if(!factor) {
	free(x);
	free(y);
	free(z);
	perror("malloc");
	return EXIT_FAILURE;
}
factor[0] = 1;
for(int i=0; i < n-1; i++) {
	factor[i+1] = factor[i]/2;
}
#pragma omp parallel for schedule(static)
for (int i=0; i < n; i++) {
	x[i] = factor[i] * y[i];
}
free(factor);
#endif
