#include <stdio.h>
#include <math.h>

int
binom(int n, int k) {
	int sum = 0;
	for (int i = 0; i <= k; i++)
		sum += (int) pow( (double) 2, (double) n);
	/* for (int i = 1; i <= k; i++) */
		/* prod *= (n + 1 - i) / i; */
	return sum;
	/* return binom(n, k - 1) * ((n + 1 - k) / k); */
	/* return pow(n, k) */
}

void
spaces(int n) {
	for (int i = 0; i < n; i++)
		putchar(' ');
}

void
triangle(int rows) {
	for (int i = 0; i < rows; i++) {
		spaces(rows - i - 1);
		for (int j = 0; j <= i; j++)
			printf("%d ", binom(j, i));
		putchar('\n');
	}
}

int
main(int argc, char **argv) {
	for (int i = 0; i < 10; i++) {
		printf("Printing a triangle of %d size.\n", i);
		triangle(i);
	}
}

