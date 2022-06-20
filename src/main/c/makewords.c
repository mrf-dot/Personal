#include <stdio.h>

int
makewords(char *file) {
	FILE *f;
	if (f = fopen(file, "r")) {
		for (int i = getc(f); i != EOF; i = getc(f))
			if (i == ' ')
				putchar('\n');
			else
				putchar(i);
		return 0;
	}
	else
		return 1;
}

int
main(int argc, char **argv) {
	if (argc == 1)
		return 1;
	return makewords(argv[1]);
}

