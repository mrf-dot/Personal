/*
 * REFERENCE:
 * A Brainfuck program has a pointer that moves within an array
 * of 30000 bytes, initially all set to zero.  The pointer
 * initially points to the beginning of this array.  The language
 * has eight commands, each of which is represented as a single
 * character, and which can be expressed in terms of {C} as
 * follows:
 *
 * >   ==>    ++p;
 * <   ==>    --p;
 * +   ==>    ++*p;
 * -   ==>    --*p;
 * .   ==>    putchar(*p);
 * ,   ==>    *p = getchar();
 * [   ==>    while (*p) {
 * ]   ==>    }
 *
 * {Brian Raiter's Brainfuck page
 * (http://muppetlabs.com/~breadbox/bf/)}.
 */

#include <stdio.h>
#include <string.h>

#define SLC "// "
#define RESERVED "><+-.,[]"
#define WHITESPACE  " \t\r\n"
#define BOILERPLATE "#include <stdio.h>\n\
#include <stdlib.h>\n\
\n\
int\n\
main() {\n\
\tchar *p = malloc(30000);\n"

FILE *ifile;
FILE *ofile;

int
cpos(char c, const char *s) {
	for (int i = 0; s[i] != '\0'; i++)
		if (s[i] == c)
			return i;
	return -1;
}

void
bf2c() {
	int c, ilevel = 1, iscom = 0;
	fputs(BOILERPLATE, ofile);
	while ((c = getc(ifile)) != EOF) {
		if (iscom && (cpos(c, RESERVED) != -1 || c == '\n')) {
			putc('\n', ofile);
			iscom = 0;
		}
		if (!iscom && (cpos(c, WHITESPACE) != -1))
			continue;
		if (c == ']')
			ilevel--;
		for (int i = 0; !iscom && i < ilevel; i++)
			putc('\t', ofile);
		switch(c) {
		case '>':
			fputs("++p;", ofile);
			break;
		case '<':
			fputs("--p;", ofile);
			break;
		case '+':
			fputs("++*p;", ofile);
			break;
		case '-':
			fputs("--*p;", ofile);
			break;
		case '.':
			fputs("putchar(*p);", ofile);
			break;
		case ',':
			fputs("*p = getchar();", ofile);
			break;
		case '[':
			fputs("while (*p) {", ofile);
			ilevel++;
			break;
		case ']':
			putc('}', ofile);
			break;
		default:
			if (!iscom) {
				fputs(SLC, ofile);
				iscom = 1;
			}
			if (c == '\\' || c == '?')
				putc('\\', ofile);
			putc(c, ofile);
			continue;
		}
		putc('\n', ofile);
	}
	fputs("}\n\n", ofile);
}

int
ostreams(const char *src, const char *target) {
	if (!strcmp(src, "-")) {
		ifile = stdin;
	} else if (!(ifile=fopen(src, "r"))) {
		fputs("Cannot read input file\n", stderr);
		return 1;
	}
	if (!strcmp(target, "-")) {
		ofile = stdout;
	} else if (!(ofile=fopen(target, "w+"))) {
		fputs("Cannot write to output file\n", stderr);
		return 1;
	}
	return 0;
}

int
main(int argc, char **argv) {
	switch (argc) {
	case 1:
		ostreams("-", "-");
		break;
	case 2:
		if (ostreams(argv[1], "-"))
			return 1;
		break;
	case 3:
		if (ostreams(argv[1], argv[2]))
			return 1;
		break;
	default:
		fputs("Too many arguments", stderr);
		return 1;
	}
	bf2c();
	return 0;
}

