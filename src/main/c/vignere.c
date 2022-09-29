#include <stdio.h>
#include <string.h>

#define STRSIZE 1000

void
lowercase(char *s) {
	for (int i = 0; s[i] != '\0'; i++)
		if (s[i] >= 'A' && s[i] <= 'Z')
			s[i] += 'a' - 'A';
}

int
isvalidkey(char *k) {
	for (int i = 0; k[i] != '\0'; i++)
		if (k[i] < 'a' || k[i] > 'z')
			return 0;
	return 1;
}

void
encrypt(char *p, char *k) {
	int pc, kc;
	for (int i = 0; p[i] != '\0'; i++) {
		if ((p[i] >= 'A' && p[i] <= 'Z') || (p[i] >= 'a' && p[i] <= 'z')) {
			p[i] = (p[i] <= 'Z' ? 'A' : 'a') + ((p[i] >= 'a' ? p[i] - 'a' : p[i] - 'A') + (k[i % (strlen(k) - 1)] - 'a')) % 26;
		}
	}
}

int
main(int argc, char **argv) {
	char p[STRSIZE], k[STRSIZE];
	fputs("Enter a string to be encrypted: ", stdout);
	fgets(p, STRSIZE, stdin);
	/* Continuously prompts the client until a key with only A-z is given */
	fputs("Enter a key: ", stdout);
	fgets(k, STRSIZE, stdin);
	lowercase(k);
	if (isvalidkey(k)) {
		fputs("Key must contain only letters.", stderr);
		return 1;
	}
	encrypt(p, k);
	printf("Your encrypted string: %s", p);
	return 0;
}

