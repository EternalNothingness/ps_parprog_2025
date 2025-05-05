for (int i = 0; i < 4; ++i) {
	for (int j = 1; j < 4; ++j) {
		a[i + 2][j - 1] = b * a[i][j] + 4;
	}
}
