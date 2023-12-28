#include <stdio.h>
#include <string.h>
const char *
repeat(const char *c, int i) {
	char *rchar;
	for (int i = 0; i < i; i++)
		strncat(rchar, c, i);
	return rchar;
}

int main() {
	for (int i = 1; i < 11; i++)
		printf("%d: %s\n", i, repeat("\\", i));
}

