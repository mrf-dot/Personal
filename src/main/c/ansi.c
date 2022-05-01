#include <stdio.h>

int
main(void) {
	printf("\n\e[1;4m256-Color Foreground & Background Charts\e[0m");
	for (int i = 38; i < 49; i++) {
		for (int j = 0; j < 256; j++) {
			printf("\e[%d;5;%dm%d    \e[0m", i, j, j);
			if ((j+1) % 6 == 4) {
				putchar('\n');
			}
		}
	putchar('\n');
	}
}

