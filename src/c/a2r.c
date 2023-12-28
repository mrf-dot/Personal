#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUMERALS 13
#define MVAL 3999
#define MLEN 15

const char *rnums[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
const int anums[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
char rstr[16];

void
a2r(int n) {
	int i;
	while (n > 0)
		for (i = 0; i < NUMERALS; i++)
			if (n >= anums[i]) {
				strcat(rstr, rnums[i]);
				n -= anums[i];
				break;
			}
}

int
r2a(char *s) {
	int i = 0, sum = 0, j;
	while (s[i] != '\0') {
		for (j = 0; j < NUMERALS; j++)
			if (!strncmp(s + i, rnums[j], strlen(rnums[j]))) {
				sum += anums[j];
				i += strlen(rnums[j]);
				break;
			}
		if (j == NUMERALS)
			return -1;
	}
	return sum;
}

void
uppercase(char *s) {
	for (int i = 0; s[i] != '\0'; i++)
		if (s[i] >= 'a' && s[i] <= 'z')
			s[i] -= 'a' - 'A';
}

int
main(int argc, char **argv) {
	int n;
	if (argc != 2) {
		fprintf(stderr, "%s: Must be supplied exactly one argument\n", argv[0]);
		return 1;
	}
	if (!strcmp("a2r", argv[0])) {
		n = atoi(argv[1]);
		if (n < 1 || n > 3999) {
			fprintf(stderr, "%s: Maximum value is 3999 and minimum value is 1\n", argv[0]);
			return 1;
		}
		a2r(n);
		puts(rstr);
	}
	if (!strcmp("r2a", argv[0])) {
		uppercase(argv[1]);
		if ((n = r2a(argv[1])) == -1) {
			fprintf(stderr, "%s: Invalid Roman numeral provided\n", argv[0]);
			return 1;
		}
		printf("%d\n", n);
	}
	return 0;
}

