#include <stdio.h>
#include <math.h>

#define PHI 1.618033988749

unsigned long long
fib(int n) {
	return (pow(PHI, n) / sqrt(5)) + 0.5;
}


int
main(int argc, char **argv) {
	for (int i = 0; i < 101; i++)
		printf("%d:\t%llu\n", i, fib(i));
	return 1;
}

