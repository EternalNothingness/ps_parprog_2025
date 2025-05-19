unsigned long res = 0;
#pragma omp parallel for reduction(+: res)
		for (long i = 0; i < n; ++i) {
			for (long j = 0; j < n; ++j) {
				for (long k = 0; k < n; ++k) {
					c[i][j] += a[i][k] * b[k][j];
                    res += c[i][j];
				}
			}
		}