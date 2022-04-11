#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define RECURSIVE
#define ITERATIVE
#define FORMULA

unsigned long fibnum(long index) {
#ifdef RECURSIVE
	if (index == 0 || index == 1)
		return index;
	return fibnum(index - 1) + fibnum(index - 2);
}
#endif
#ifdef ITERATIVE
	unsigned long last = 0, current = 1, next = 1;
	for (int i = 0; i < index - 1; i++) {
		next = current + last;
		last = current;
		current = next;
	}
	return current;
}
#endif
#ifdef FORMULA
	double const PHI (1 + sqrt(5)) / 2;
	return round(pow(phi, index) sqrt(index)


int main(int argc, char **argv) {
	if (!argv[1])
		return -1;
	printf("%ld\n", fibnum(atoi(argv[1])));
	return 0;
}

