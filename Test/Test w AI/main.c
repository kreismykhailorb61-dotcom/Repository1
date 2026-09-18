#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// 1. Підінтегральна функція за варіантом №1: f(x) = 1 / (4 + x^2)
double f(double x) {
    return 1.0 / (4.0 + x * x);
    //return x * x + 2.0 * x;
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

// 3. Метод правих прямокутників
double right_rectangle(double a, double b, unsigned int n) {
    double h = (b - a) / n;
    double sum = 0.0;
    for (unsigned int i = 1; i <= n; i++) {
        double x = a + i * h;
        sum += f(x);
    }
    return sum * h;
}

// 4. Метод трапецій
double trapezoidal(double a, double b, unsigned int n) {
    double h = (b - a) / n;
    double sum = (f(a) + f(b)) / 2.0;
    for (unsigned int i = 1; i < n; i++) {
        double x = a + i * h;
        sum += f(x);
    }
    return sum * h;
}

// 5. Метод Парабол (Сімпсона) - вимагає парну кількість проміжків
double simpson(double a, double b, unsigned int n) {
    if (n % 2 != 0) n++; // Перевірка на парність
    double h = (b - a) / n;
    double sum = f(a) + f(b);

    for (unsigned int i = 1; i < n; i++) {
        double x = a + i * h;
        if (i % 2 == 0) {
            sum += 2.0 * f(x);
        } else {
            sum += 4.0 * f(x);
        }
    }
    return (h / 3.0) * sum;
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

int main() {
    //Введення основних змінних для рівняння
    double a = 0.0;  // Ліва межа інтегрування (або нижня межа)
    double b = 1.0; // Права межа інтегрування (або верхня межа)
    int choice;
    unsigned int n;
    double eps;

    printf("===================================================\n");
    printf("   CALCULATING A DEFINITE INTEGRAL (Option 1)   \n");
    printf("   The integral of 1/(4+x^2) dx over the interval [0, 1]    \n");
    printf("===================================================\n\n");

    printf("1. Calculate based on a given number of intervals N\n");
    printf("2. Find N to achieve the specified error eps\n");
    printf("3. A comparison table for all methods\n");
    printf("Select a mode (1-3): ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("\nEnter the number of intervals, N (e.g. 10, 100, 1000): ");
        scanf("%u", &n);

        printf("\n--- Results (N = %u) ---\n", n);
        printf("Left_rectangle method:  %.8lf\n", left_rectangle(a, b, n));
        printf("Right_rectangle method: %.8lf\n", right_rectangle(a, b, n));
        printf("Trapezoidal method:             %.8lf\n", trapezoidal(a, b, n));
        printf("Method parabol (simpson):   %.8lf\n", simpson(a, b, n));

    } else if (choice == 2) {
        printf("\nEnter the eps error (for example, 0.0001): ");
        scanf("%lf", &eps);

        printf("\n--- The required value of N and the result for eps = %lf ---\n", eps);

        n = find_n_for_precision(a, b, eps, left_rectangle);
        printf("left_rectangle:  N = %5u | I = %.8lf\n", n, left_rectangle(a, b, n));

        n = find_n_for_precision(a, b, eps, right_rectangle);
        printf("right_rectangle: N = %5u | I = %.8lf\n", n, right_rectangle(a, b, n));

        n = find_n_for_precision(a, b, eps, trapezoidal);
        printf("trapezoidal:     N = %5u | I = %.8lf\n", n, trapezoidal(a, b, n));

        n = find_n_for_precision(a, b, eps, simpson);
        printf("Method parabol (simpson):     N = %5u | I = %.8lf\n", n, simpson(a, b, n));

    } else if (choice == 3) {
        unsigned int steps[] = {10, 100, 1000, 10000};
        printf("\n+--------------------+--------------+--------------+--------------+--------------+\n");
        printf("| Method / N          | N = 10       | N = 100      | N = 1000     | N = 10000    |\n");
        printf("+--------------------+--------------+--------------+--------------+--------------+\n");

        printf("| left_rectangle  ");
        for(int i = 0; i < 4; i++) printf("| %.8lf ", left_rectangle(a, b, steps[i]));
        printf("|\n");

        printf("| right_rectangle ");
        for(int i = 0; i < 4; i++) printf("| %.8lf ", right_rectangle(a, b, steps[i]));
        printf("|\n");

        printf("| trapezoidal          ");
        for(int i = 0; i < 4; i++) printf("| %.8lf ", trapezoidal(a, b, steps[i]));
        printf("|\n");

        printf("| Method parabol (simpson) ");
        for(int i = 0; i < 4; i++) printf("| %.8lf ", simpson(a, b, steps[i]));
        printf("|\n");
        printf("+--------------------+--------------+--------------+--------------+--------------+\n");
    }

    return 0;
}
