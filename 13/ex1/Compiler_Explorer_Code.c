#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define N 1000

void a(unsigned c1) {
    unsigned c2 = 32 * c1;
    printf("a): %u\n", c2);
}

void a_solution(unsigned c1) {
    unsigned c2 = c1 << 5;
    printf("a): %u\n", c2);

}

void b(unsigned c1) {
    unsigned c2 = 15 * c1;
    printf("b): %u\n", c2);
}

void b_solution(unsigned c1) {
    unsigned c2 = (c1 << 4) - c1;
    printf("b): %u\n", c2);

}

void c(unsigned c1) {
    unsigned c2 = 96 * c1;
    printf("c): %u\n", c2);
}

void c_solution(unsigned c1) {
    unsigned c2 = c1 << 6 + c1 << 5;
    printf("c): %u\n", c2);
}

void d(unsigned c1) {
    unsigned c2 = 0.125 * c1;
    printf("d): %u\n", c2);
}

void d_solution(unsigned c1) {
    unsigned c2 = c1 >> 3;
    printf("d): %u\n", c2);
}

void e(unsigned *a) {
    unsigned sum_fifth = 0;
    for (int i = 0; i < N / 5; ++i) {
        sum_fifth += a[5 * i];
    }
    printf("e): %u\n", sum_fifth);
}

void e_solution(unsigned *a) {
    unsigned sum_fith = 0;

    for (int i = 0; i < N; i += 5) {
        sum_fith += a[i];
    }
    printf("e): %u\n", sum_fith);

}


void f(double *a) {
    for (int i = 0; i < N; ++i) {
        a[i] += i / 5.3;
    }
    printf("f):");
    for (int i = 0; i < N; ++i) {
        printf("%lf, ", a[i]);
    }
}

void f_solution(double *a) {
    double factor = 1 / 5.3;
    for (int i = 0; i < N; ++i) {
        a[i] += factor * i;
    }
    printf("f):");
    for (int i = 0; i < N; ++i) {
        printf("%lf, ", a[i]);
    }
}

void g(float c1) {
    float c2 = -1 * c1;
    printf("g): %u\n", c2);
}

void g_solution(float c1) {
    union {
        int32_t i;
        float f;
    } c;
    
    c.f = c1;
    //flip MSB; note that INT32_MAX == 01...1
    c.i = ~INT32_MAX ^ c.i;
    float c2 = c.f;
    printf("g): %u\n", c2);
}

int main(void) {
    return EXIT_SUCCESS;
}
