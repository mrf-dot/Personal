#include <stdio.h>
#include <math.h>

int
main(int argc, char **argv) {
	int eleven = 0;
	for (int i = 0; i < 8; i++) {
		eleven += pow(10, i);
		printf("%ld\n", (long) pow(eleven, 2));
	}
}

