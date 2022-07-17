/*
 * Convert between different temperature units
 * lowercase flags denote origin temperature sign
 * uppercase flags denote converted temperature sign
 * Temperature conversion is done with macros
 * Example: Convert 20 C to F
 * INPUT: temp -c 20 -F
 * OUTPUT: 68
 * */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define MAX 20
#define F2C(T) (((T) - 32) * (0.5555))
#define K2C(T) ((T) - 273.15)
#define R2C(T) (((T) - 491.67) * (0.5555))
#define C2F(T) ((T) * 1.8 + 32)
#define C2K(T) ((T) + 273.15)
#define C2R(T) (((T) + 273.15) * 1.8)
#define HELP "TEMP: Authored by Mitch Feigenbaum\n\
temp [-<unit> <VAL>] [-<UNIT>]\n\
temp [-<unit> <VAL> -<unit> <VAL> -<unit> <VAL>] [-<UNIT> -<UNIT> -<UNIT>]\n\
OPTIONS:\n\
\t-c<n>\t\tConvert a temperature from Celsius\n\
\t-C\t\tConvert a temperature to Celsius\n\
\t-f<n>\t\tConvert a temperature from Fahrenheit\n\
\t-F\t\tConvert a temperature to Fahrenheit\n\
\t-h\t\tPrint this help message\n\
\t-k<n>\t\tConvert a temperature from Kelvin\n\
\t-K\t\tConvert a temperature to Kelvin\n\
\t-r<n>\t\tConvert a temperature from Rankine\n\
\t-R\t\tConvert a temperature to Rankine\n"

int
main(int argc, char **argv) {
	float ivals[MAX];
	char ounits[MAX];
	int nvals = 0;
	int nunits = 0;
	if (argc == 1) {
		fputs(HELP, stderr);
		return 1;
	}
	if (argc > MAX) {
		fputs("Too many arguments.\n", stderr);
		return 1;
	}
	int c;
	while ((c = getopt(argc, argv, "c:f:k:r:CFKRvh")) != -1)
		switch(c) {
			case 'c':
				ivals[nvals++] = strtof(optarg, NULL);
				break;
			case 'f':
				ivals[nvals++] = F2C(strtof(optarg, NULL));
				break;
			case 'k':
				ivals[nvals++] = K2C(strtof(optarg, NULL));
				break;
			case 'r':
				ivals[nvals++] = R2C(strtof(optarg, NULL));
				break;
			case 'C':
				ounits[nunits++] = 'c';
				break;
			case 'F':
				ounits[nunits++] = 'f';
				break;
			case 'K':
				ounits[nunits++] = 'k';
				break;
			case 'R':
				ounits[nunits++] = 'r';
				break;
			case 'h':
				fputs(HELP, stdout);
				break;
			case '?':
			default:
				return 1;
		}
	for (int i = optind; i < argc; i++)
		fprintf(stderr, "non-option argument: %s\n", argv[i]);
	if (nvals != nunits) {
		fputs("Input values are not equal to output units\n", stderr);
		return 1;
	}
	for (int i = 0; i < nunits; i++)
		switch (ounits[i]) {
			case 'c':
				printf("%.2f %c\n", ivals[i], 'C');
				break;
			case 'f':
				printf("%.2f %c\n", C2F(ivals[i]), 'F');
				break;
			case 'k':
				printf("%.2f %c\n", C2K(ivals[i]), 'K');
				break;
			case 'r':
				printf("%.2f %c\n", C2R(ivals[i]), 'R');
				break;
			default:
				fputs("Error in temperature unit conversion", stderr);
				return 1;
		}
	return 0;
}

