#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

#define PHI 1.618033988749895

uint64_t
fib(int n) {
	double numerator = pow(PHI, n) - pow(-PHI, -n);
	double denominator = sqrt(5);
	printf("The numerator is %f\n", numerator / denominator);
	return numerator / denominator;
}


int
main(int argc, char **argv) {
	for (int i = 0; i < 101; i++)
		printf("%d:\t%ld\n", i, fib(i));
	return 1;
}

