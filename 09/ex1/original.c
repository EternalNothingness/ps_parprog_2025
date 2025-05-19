#pragma omp parallel default(none) shared(n, a, b, c, local_res)
	{
		// matrix multiplication
#pragma omp parallel for default(none) shared(n, a, b, c)
		for (long i = 0; i < n; ++i) {
			for (long j = 0; j < n; ++j) {
				for (long k = 0; k < n; ++k) {
					c[i][j] += a[i][k] * b[k][j];
				}
			}
		}

		// sum of matrix c
#pragma omp parallel for default(none) shared(n, a, b, c, local_res)
		for (long i = 0; i < n; ++i) {
			for (long j = 0; j < n; ++j) {
				local_res[omp_get_thread_num()] += c[i][j];
			}
		}
	}
	unsigned long res = 0;
	for (int l = 0; l < omp_get_num_threads(); ++l) {
		res += local_res[l];
	}