/* My implementation of the yes program for unix */
#include <stdio.h>

int
main(argc, argv)
	int argc;
	char **argv; {
	const char *s = *(argv+1) ? *(argv+1) : "y";
	while (1)
		puts(s);
	return 0;
}

