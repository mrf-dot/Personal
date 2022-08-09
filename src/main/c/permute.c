#include <stdio.h>

void
swap(char *s1, char *s2) {
	char tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}

void
permute(char *s, int lo) {
	if (*(s+lo) == '\0')
		puts(s);
	else for (int i = lo; *(s+i) != '\0'; i++) {
		swap(s, s+i);
		permute(s, lo+1);
		swap(s, s+i);
	}
	putchar('\0');
}

int
main(int argc, char **argv) {
	char s[] = "ABC";
	permute(s, 0);
}

