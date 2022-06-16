/* Program to show how many of each ascii character a file contains */
#include <stdio.h>
#include <unistd.h>

#define CTRL 0x1F
#define DEL 0x7F
#define ASCII 0xFF
#define ROWS 32
#define COLS 8

int control = 0;
int unicode = 0;
int total = 0;
int cnt[ASCII - CTRL];

int
count(char *file) {
	FILE *f;
	if (f=fopen(file, "r")) {
		for (int c = getc(f); c != EOF; c = getc(f)) {
			if (c > 0xFF)
				unicode++;
			else if (c <= CTRL || c == DEL)
				control++;
			else
				cnt[c - CTRL]++;
			total++;
		}
		return 0;
	} else {
		return 1;
	}
}

void
stats() {
	int printable = total - control - unicode;
	printf("Control characters (Unprintable):\t%d\n\
Printable characters:\t%d\n\
Unicode:\t%d\n\
Total:\t%d\n",
	control, printable, unicode, total);
}

void
prchart() {
	if (cnt[0] > 0)
		printf("SPACE:\t%d\n", cnt[0]);
	for (int i = 2; i < ASCII - CTRL; i++)
		if (cnt[i] > 0)
			printf("%c:\t%d\n", CTRL + i, cnt[i]);
}

void
help() {
	puts("Enter a file");
}

int
main(int argc, char **argv) {
	if (argc == 1) {
		help();
		return 1;
	}
	if (count(argv[1]))
		return 1;
	prchart();
	stats();
	return 0;
}

