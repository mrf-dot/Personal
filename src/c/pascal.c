#include <stdio.h>

void
pascal(int i) {
	int prev, n, k, t;
	for (n = 0; n <= i; n++) {
		prev = 1;
		for (k = 0; k <= n; k++) {
			printf("%d ", prev);
			prev = prev * (n-k) / (k+1);
		}
		putchar('\n');
	}
}

int
main(int argc, char **argv) {
	pascal(20);
	return 0;
}

