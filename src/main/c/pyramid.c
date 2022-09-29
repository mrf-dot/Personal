#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char **argv) {
	for (int i = 0; i < atoi(argv[1]); i++) {
		for (int j = 0; j < i; j++)
			putchar('*');
		putchar('\n');
	}
	return 0;
}

