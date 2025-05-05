#pragma omp parallel for schedule(static)
for (int i = 0; i < 2; ++i) {
	for (int j = 1; j < 4; ++j) {
		a[i + 2][j - 1] = b * a[i][j] + 4;
	}
}

#pragma omp parallel for schedule(static)
for(int i = 2; i < 4; ++i) {
	for (int j = 1; j < 4; ++j) {
		a[i+2][j-1] = b * a[i][j] + 4;
	}
}
