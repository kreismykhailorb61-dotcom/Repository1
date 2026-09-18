#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define Name "Misha"
#define LastName "Kreys"
#define GroupName "RB-61"
#define Faculty "RTF"
#define University "Igor Sikorsky KPI"

int main()
{
int option;
double x, y;
printf("X:");
while (scanf("%lf", &x) != 1) {
        while (getchar() != '\n'); // Очищення буфера вводу
        printf("x: ");
    }
if (x >= -5.0 && x < 0.0) {
        y = x * x + 2.0 * x + 1.0;
    }
    else if (x >= 0.0 && x < 10.0) {
        y = 1.0 / sqrt(x + 1.0);
    }
    else if (x >= 10.0 && x < 1000.0) {
        y = log10(x) + 2.0 * x;
    }
    else {
        y = x / 2.0;
    }
printf("Result: x = %.4lf ==> y = %.6lf\n", x, y);

}
