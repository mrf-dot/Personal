// Program prints every ascii letter in order
#include <stdio.h>

#define NCHARS 128
int
main() {
	for (int i = 0; i < NCHARS; i++) {
		printf("%c\n", i);
	}
	return 0;
}

