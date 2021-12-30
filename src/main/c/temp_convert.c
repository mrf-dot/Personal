#include <stdio.h>

void
print_temp(int lower, int upper, int step) {
        printf("Celcius\t\tFahrenheit\n");
        printf("-------\t\t----------\n");
        double fahrenheit;
        for (double i = lower; i < upper; i += step) {
                fahrenheit = i * 1.8 + 32;
                printf("%f\t%f\n", i, fahrenheit);
        }
}

int
main() {
        printf("Please give in a lower limit, limit >= 0: ");
        const int lower;
        do {
                scanf("%d", &lower);
        } while (lower < 0 );
        printf("Please give in a higher limit, %d < limit <= 50000: ", lower);
        const int upper;
        do {
                scanf("%d", &upper);
        } while (upper <= lower || upper > 50000);
        printf("Please give in a step, 0 < step <= %d: ", lower);
        const int step;
        do {
                scanf("%d", &step);
        } while (step <= 0 || step > lower);
        print_temp(lower, upper, step);
}

