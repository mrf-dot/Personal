/* My implementation of the "strings" program in C */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char *
ftobuf(const char *fn) {
	FILE *f = fopen(fn, "rb");
	fseek(f, 0, SEEK_END);
	long sz = ftell(f);
	printf("size: %ld\n", sz);
	rewind(f);
	char *fb;
	if (!(fb = malloc(sz + 1))) {
		fprintf(stderr, "Unable to allocate buffer for file: %s\n", fn);
		exit(1);
	}
	printf("%ld", fread(fb, sz, 1, f));
	if (fread(fb, sz, 1, f) != sizeof(*fb)) {

		fprintf(stderr, "Unable to read file: %s\n", fn);
		/* exit(1); */
	}
	fclose(f);
	return fb;
}

void
strparse(const char *fn) {
	char *fb = ftobuf(fn);
	puts(fb);
	while (*fb) {
		if (*fb >= ' ' && *fb <= '~') {
			while (*fb >= ' ' && *fb <= '~')
				putchar(*(fb++));
			putchar('\n');
		} else {
			fb++;
		}
	}
	/* free(fb); */
}

int
main(int argc, char **argv) {
	if (argc == 1) {
		fputs("Must supply a filename as an argument\n", stderr);
		return 1;
	}
	for (int i = 1; i < argc; i++) {
		if (!access(argv[i], F_OK)) {
			strparse(argv[i]);
		} else {
			fprintf(stderr, "Invalid filename: %s\n", argv[i]);
			return 1;
		}
	}
	return 0;
}

