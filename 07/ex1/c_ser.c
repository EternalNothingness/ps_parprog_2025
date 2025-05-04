for (int i=0; i < n; i++) {
	x[i] = y[i] * 2 + b * i; // S1
}

for (int i=0; i < n; i++) {
	y[i] = x[i] + a / (i+1); // S2
}
