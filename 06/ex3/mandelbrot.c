#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

// Include that allows to print result as an image
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

// Default size of image
#define X 1280
#define Y 720
#define MAX_ITER 10000

#ifndef SCHEDULING
    #define SCHEDULING auto
#endif

void calc_mandelbrot(uint8_t image[Y][X]) {
	size_t i, j;
	#pragma omp parallel for schedule(SCHEDULING) private(j)
	for(i=0; i<Y; ++i) {
		for(j=0; j<X; ++j) {
			double x=0;
			double y=0;
			double cx=(double)j/(X-1)*3.5-2.5; // scale j to [-2.5, 1]
			double cy=(double)i/(Y-1)*2-1; // scale i to [-1. 1]
			size_t iteration=0;
			while(x*x+y*y<2*2 && iteration<MAX_ITER) {
				double x_tmp=x*x-y*y+cx;
				y=2*x*y+cy;
				x=x_tmp;
				iteration=iteration+1;
			}
			// scale iteration to [0,255]
			char norm_iteration=iteration*255/MAX_ITER; 
			image[i][j]=norm_iteration;
		}
	}
}

int main() {
	uint8_t image[Y][X];

    double startTime = omp_get_wtime();
	calc_mandelbrot(image);
	double endTime = omp_get_wtime();
	printf("%2.4f\n", endTime-startTime);

	const int channel_nr = 1, stride_bytes = 0;
	stbi_write_png("mandelbrot.png", X, Y, channel_nr, image, stride_bytes);
	return EXIT_SUCCESS;
}