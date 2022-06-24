#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void
mchar(char c, int n) {
	for (int i = 0; i < n; i++)
		putchar(c);
}

void
pbar(int seconds) {
	float percent;
	fflush(stdout);
	for (int i = seconds; i >= 0; i--) {
		fflush(stdout);
		putchar('\r');
		percent = 100 - ((float) i * 100 / seconds);
		printf("Time remaining: \e[33m%d (%.1f%%) ", i, percent);
		fputs("\e[38;5;14m[", stdout);
		mchar('#', (int) percent);
		mchar('.', 100 - (int) percent);
		fputs("]\e[0m", stdout);
		sleep(1);
	}
	putchar('\n');
}

int
main(int argc, char **argv) {
	if (argc == 1)
		return 1;
	pbar(atoi(argv[1]));
	return 0;
}

