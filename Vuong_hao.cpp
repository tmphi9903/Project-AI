#include <stdio.h>
#include <math.h>

#define MAX_ITERATIONS 100
#define TOLERANCE 0.001

double f(double x) {
    // Ham so f(x) con tinh nghiem
    return x*x - 2;
}

double f_prime(double x) {
    // Dao ham cua ham so f(x)
    return 2*x;
}

double vuong_hao(double x_0) {
    int i = 0;
    double x_i = x_0;
    double x_i_1 = 0;

    while (i < MAX_ITERATIONS) {
        x_i_1 = x_i - f(x_i) / f_prime(x_i);

        if (fabs(x_i_1 - x_i) < TOLERANCE) {
            // Dat duoc do chinh xac mong muon
            return x_i_1;
        }

        x_i = x_i_1;
        i++;
    }

    // Khong tim duoc nghiem
    printf("Khong tim duoc nghiem trong %d buoc lap.\n", MAX_ITERATIONS);
    return NAN;
}

int main() {
    double x_0 = 1.0; 
    double root = vuong_hao(x_0);

    if (!isnan(root)) {
        printf("Nghiem cua phuong trinh la: %lf\n", root);
    }

    return 0;
}
