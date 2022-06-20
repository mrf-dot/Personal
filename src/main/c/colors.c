#include <stdio.h>
#include <unistd.h>

#define FG	38
#define BG	48
#define ANSI	8
#define COLORS	256
#define RLEN	6
#define MAGIC	4

void
longfg(int colors) {
	for (int i = 0; i < colors; i++) {
		if (i < ANSI)
			printf("\\[%dm\t\t", FG - ANSI + i);
		else
			printf("\\[%d;5;%d\t", FG, i);
		printf("\033[%d;5;%dm%4d\033[0m\n", FG, i, i);
	}
}

void
longbg(int colors) {
	for (int i = 0; i < colors; i++) {
		if (i < ANSI)
			printf("\\[%dm\t\t", BG - ANSI + i );
		else
			printf("\\[%d;5;%d\t", BG, i);
		printf("\033[%d;5;%dm%4d\033[0m\n", BG, i, i);
	}
}

void
fg(int colors) {
	for (int i = 0; i < colors; i++) {
		printf("\033[%d;5;%dm%4d\033[0m", FG, i, i);
		if ((i + 1) % RLEN == MAGIC)
			putchar('\n');
	}
}

void
bg(int colors) {
	for (int i = 0; i < colors; i++) {
		printf("\033[%d;5;%dm%4d\033[0m", BG, i, i);
		if ((i + 1) % RLEN == MAGIC)
			putchar('\n');
	}
}

void
colors(int colors, int verbose) {
	puts("Foreground Colors\n");
	if (verbose) {
		longfg(colors);
		puts("\nBackground Colors\n");
		longbg(colors);
	} else {
		fg(colors);
		puts("\nBackground Colors\n");
		bg(colors);
	}
}

void
styles() {
	puts("\\[0m\t\033[0mReset/Normal\n\
\\[1m\t\033[1mBold\033[0m\n\
\\[2m\t\033[2mDim\033[0m\n\
\\[3m\t\033[3mItalic\033[0m\n\
\\[4m\t\033[4mUnderline\033[0m\n\
\\[5m\t\033[5mSlow blink\033[0m\n\
\\[6m\t\033[6mRapid blink\033[0m\n\
\\[7m\t\033[7mReverse/Invert\033[0m\n\
\\[8m\t\033[8mConceal\033[0m\n\
\\[9m\t\033[9mStrike\033[0m");
}

void
help() {
	puts("COLORS: Authored by Mitch Feigenbaum\n\
Options:\n\
\t-b\t\tPrint the original ANSI colors (8)\n\
\t-c\t\tPrint the 8 Bit display colors (256)\n\
\t-h\t\tPrint this help message\n\
\t-l\t\tPrint each color on a separate line\n\
\t-s\t\tShow text styling settings");
}

int
main(int argc, char **argv) {
	if (argc == 1) {
		help();
		return 1;
	}
	int c;
	while ((c = getopt(argc, argv, "hbcls")) != -1)
		switch(c) {
			case 'h':
				help();
				break;
			case 'b':
				colors(ANSI, 1);
				break;
			case 'c':
				colors(COLORS, 0);
				break;
			case 'l':
				colors(COLORS, 1);
				break;
			case 's':
				styles();
				break;
			case '?':
			default:
				return 1;
		}
	for (int i = optind; i < argc; i++)
		fprintf(stderr, "non-option argument: %s\n", argv[i]);
	return 0;
}

