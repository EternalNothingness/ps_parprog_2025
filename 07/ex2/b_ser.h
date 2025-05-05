for (int i=1; i<n; i++) {
	x[i] =(x[i] + y[i-1]) / 2;
	y[i] = y[i] +z[i] * 3;
}
