/* from https://en.wikipedia.org/wiki/Body_mass_index
 *
 * old bmi:
 * kg / m ** 2
 * new bmi: (accounts for short and tall people)
 * 1.3 * (kg / m ** 2.5)
 * classifcations:
 * < 16.0 (seveire thiness)
 * 16.0 - 16.9 (moderate thinness)
 * 17.0 - 18.4 (mild thinness)
 * 18.5 - 24.9 (normal)
 * 25.0 - 29.9 (overweight)
 * 30.0 - 34.9 (obese class I)
 * 35.0 - 39.9 (obese class II)
 * >= 40 (obese class III)
 * compiler argument must include -lm
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define CM2M(X) ((X) / 100)
#define I2M(X) ((X) / 39.37)
#define FT2M(X) ((X) / 3.281)
#define LB2KG(X) ((X) / 2.205)
#define OLDBMI(KG, M) ((KG) / pow((M), 2))
#define NEWBMI(KG, M) (1.3 * ((KG) / pow((M), 2.5)))
#define INTERPRET(BMI) ((BMI) > 40 ? "Obese (III)" : (BMI) > 35 ? "Obese (II)" : (BMI) > 30 ? "Obese (I)" : (BMI) > 25 ? "Overweight" : (BMI) > 18.5 ? "Normal" : (BMI) > 17 ? "Slightly Underweight" : (BMI) > 16 ? "Underweight" : "Severely Underweight")
#define HELP "BMI -- Authored by Mitch Feigenbaum\n\
Options:\n\
\t-k\t\tMass in kilograms\n\
\t-p\t\tMass in pounds\n\
\t-c\t\tHeight in centimeters\n\
\t-f\t\tHeight in feet\n\
\t-i\t\tHeight in inches (may be used in conjunction with -f)\n\
\t-n\t\tUse the proposed \"New BMI\" (accounts for short and tall heights)\n\
\t-a\t\tAnalyze BMI qualitatively\n\
\t-h\t\tPrint this help message\n"

int
main(int argc, char **argv) {
	if (argc == 1) {
		fputs(HELP, stderr);
		return 1;
	}
	float kilograms = 0.0;
	float meters = 0.0;
	int new_bmip = 0;
	int interpretp = 0;
	char c;
	while ((c = getopt(argc, argv, "k:p:c:f:i:nah")) != -1) {
		switch(c) {
		case 'k':
			kilograms += strtof(optarg, NULL);
			break;
		case 'p':
			kilograms += LB2KG(strtof(optarg, NULL));
			break;
		case 'c':
			meters += CM2M(strtof(optarg, NULL));
			break;
		case 'f':
			meters += FT2M(strtof(optarg, NULL));
			break;
		case 'i':
			meters += I2M(strtof(optarg, NULL));
			break;
		case 'n':
			new_bmip = 1;
			break;
		case 'a':
			interpretp = 1;
			break;
		case 'h':
			fputs(HELP, stdout);
			return 0;
		default:
			return 1;
		}
	}
	for (int i = optind; i < argc; i++)
		fprintf(stderr, "non-option argument: %s\n", argv[i]);
	if (!kilograms || !meters) {
		fprintf(stderr, "%s: invalid height/mass provided\n", argv[0]);
		return 1;
	}
	float bmi = new_bmip ? NEWBMI(kilograms, meters) : OLDBMI(kilograms, meters);
	printf("%.1f\n", bmi);
	if (interpretp)
		puts(INTERPRET(bmi));
	return 0;
}

