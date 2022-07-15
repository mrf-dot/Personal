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

#include "algol.h"
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
#define INTERPRET(BMI) ((BMI) >= 40 ? "Obese (III)" : (BMI) >= 35 ? "Obese (II)" : (BMI) >= 30 ? "Obese (I)" : (BMI) >= 25 ? "Overweight" : (BMI) >= 18.5 ? "Normal" : (BMI) >= 17 ? "Slightly Underweight" : (BMI) >= 16 ? "Underweight" : "Severely Underweight")
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

INT main(argc, argv)
	INT argc;
	STRING *argv;
BEGIN
	IF argc == 1 THEN
		fputs(HELP, stderr);
		return 1
	FI
	FLOAT kilograms = 0.0;
	FLOAT meters = 0.0;
	INT new_bmip = 0;
	INT interpretp = 0;
	INT c;
	WHILE (c = getopt(argc, argv, "k:p:c:f:i:nah")) != -1
	DO
		SWITCH c
		CASE
			IN 'k':
				kilograms += strtof(optarg, NULL);
				break
			IN 'p':
				kilograms += LB2KG(strtof(optarg, NULL));
				break
			IN 'c':
				meters += CM2M(strtof(optarg, NULL));
				break
			IN 'f':
				meters += FT2M(strtof(optarg, NULL));
				break
			IN 'i':
				meters += I2M(strtof(optarg, NULL));
				break
			IN 'n':
				new_bmip = 1;
				break
			IN 'a':
				interpretp = 1;
				break
			IN 'h':
				fputs(HELP, stdout);
				return 0
			OUT
				return 1
		ESAC
	OD
	INT i = optind;
	WHILE i < argc
	DO
		fprintf(stderr, "non-option argument: %s\n", argv[i]);
		i++
	OD
	IF !kilograms || !meters THEN
		fprintf(stderr, "%s: invalid height/mass provided\n", argv[0]);
		return 1
	FI
	FLOAT bmi = new_bmip ? NEWBMI(kilograms, meters) : OLDBMI(kilograms, meters);
	printf("%.1f\n", bmi);
	IF interpretp THEN
		puts(INTERPRET(bmi))
	FI
	return 0
END

