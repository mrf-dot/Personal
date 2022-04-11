/* My implementation of the yes program for unix */
#include <stdio.h>

int main(int argc, char *argv[]) {
	char *output = argv[1] ? argv[1] : "y";
	while (1)
		printf("%s\n", output);
	return 0;
}

