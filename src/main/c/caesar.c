/* Caesar Cypher Unit 3 APCSA program in C */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define alphabet_lower = "abcdefghijklmnopqrstuvwxyz"
#define alphabet_upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

static char *
encrypt (char message[], int key) {
	encrypted_string[50];
	char current_char;
	while (message[i]) {
		i++;
	}
}

static char *
decrypt (char message[], int key) {
	return encrypt(message, 26-key);
}

int main() {
	printf("Program input: A string, a shift, encrypt/decrypt option\n");
	printf("Program output: Either a decrypted or encrypted string based on user input\n");
	printf("Enter a string: ");
	char message[50];
	scanf("%s", &message);
	printf("Enter a key (must not be 0 or a multiple of 26): ");
	int key;
	do {
		scanf("%d", &key);
		key %= 26;
	} while (key == 0);
	char mode;
	printf("Type 'e' to encrypt the string or 'd' to decrypt the string: ");
	do {
		scanf("%c", &mode);
		mode = tolower(mode);
		if (mode == 'e')
			printf("Your encrypted string is %s\n", encrypt(message, key));
		else if (mode == 'd')
			printf("Your decrypted string is %s\n", decrypt(message, key));
	} while (mode != 'e' && mode != 'd');
	return 0;
}

