/* Outputs fizzbuzz in c */
#include <stdio.h>
#include <string.h>

int main() {
	char fizzstring[20];
	for (int i = 1; i < 101; i++) {
		fizzstring[0] = '\0';
		if (i % 3 == 0)
			strcat(fizzstring, "Fizz");
		if (i % 5 == 0)
			strcat(fizzstring, "Buzz");
		if (fizzstring[0] == '\0')
			printf("%d\n", i);
		else
			puts(fizzstring);
	}
	return 0;
}

