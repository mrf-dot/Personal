#include <stdio.h>

int
makewords(char *file) {
	FILE *f;
	char c;
	if (!(f = fopen(file, "r")))
		return 1;
	while ((c = getc(f)) != EOF)
		putchar(c == ' ' || c == '\t' ? '\n' : c);
	return 0;
}

int
main(int argc, char **argv) {
	if (argc == 1)
		return 1;
	for (int i = 1; i < argc; i++)
		if (makewords(argv[i]))
			return 1;
	return 0;

}

