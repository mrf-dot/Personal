#include <stdio.h>

int
main(int argc, char **argv) {
	printf("\e[2J\e[2;H\e[m");
	return 0;
}

