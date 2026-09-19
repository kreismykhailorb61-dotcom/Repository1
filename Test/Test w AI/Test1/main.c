#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// 1. Підінтегральна функція за варіантом №1: f(x) = 1 / (4 + x^2)
double f(double x) {
    return 1.0 / (4.0 + x * x);
}
// 2. Метод лівих прямокутників
double left_rectangle(double a, double b, unsigned int n) {
    double h = (b - a) / n;
    double sum = 0.0;
    for (unsigned int i = 0; i < n; i++) {
        double x = a + i * h;
        sum += f(x);
    }
    return sum * h;
}
// Функція для пошуку кількості проміжків N із заданою точністю eps
unsigned int find_n_for_precision(double a, double b, double eps, double (*method)(double, double, unsigned int)) {
    unsigned int n = 2;
    double i1, i2;
    do {
        i1 = method(a, b, n);
        i2 = method(a, b, n + 2);
        if (fabs(i1 - i2) <= eps) {
            break;
        }
        n += 2;
    } while (n < 1000000); // Захист від нескінченного циклу
    return n + 2;
}
int main(){
//Введення основних змінних для рівняння
    double a = 0.0;  // Ліва межа інтегрування (або нижня межа)
    double b = 1.0; // Права межа інтегрування (або верхня межа)
    unsigned int n;
    double eps;

    printf("\nEnter the number of intervals, N (e.g. 10, 100, 1000): ");
        scanf("%u", &n);

        printf("\n--- Results (N = %u) ---\n", n);
        printf("Left_rectangle method:  %.8lf\n", left_rectangle(a, b, n));
}
