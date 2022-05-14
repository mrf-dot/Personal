// from https://en.wikipedia.org/wiki/Body_mass_index
//
// old bmi:
// kg / m ** 2
// new bmi: (accounts for short and tall people)
// 1.3 * (kg / m ** 2.5)
// classifcations:
// < 16.0 (seveire thiness)
// 16.0 - 16.9 (moderate thinness)
// 17.0 - 18.4 (mild thinness)
// 18.5 - 24.9 (normal)
// 25.0 - 29.9 (overweight)
// 30.0 - 34.9 (obese class I)
// 35.0 - 39.9 (obese class II)
// >= 40 (obese class III)
// compiler argument must include -lm
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

double
cm_to_m(int centimeters) {
	return (double) centimeters / 100;
}

double
ft_to_m(int feet) {
	return (double) feet / 3.281;
}

double
lb_to_kg(int pounds) {
	return (double) pounds / 2.205;
}

double
i_to_m(int inches) {
	return (double) inches / 39.37;
}

float
old_bmi(double kg, double m) {
	return kg / pow(m, 2);
}

float
new_bmi(double kg, double m) {
	return 1.3 * (kg / pow(m, 2.5));
}

void
intepretation(float bmi) {
	printf(bmi >= 40
			? "Obese (III)"
			: bmi >= 35
			? "Obese (II)"
			: bmi >= 30
			? "Obese (I)"
			: bmi >= 25
			? "Overweight"
			: bmi >= 18.5
			? "Normal"
			: bmi >= 17
			? "Slightly Underweight"
			: bmi >= 16
			? "Underweight"
			: "Severely Underweight");
	putchar('\n');
}

void
help() {
	printf("BMI -- Authored by Mitch Feigenbaum\n\
Options:\n\
\t-k\t\tMass in kilograms\n\
\t-p\t\tMass in pounds\n\
\t-c\t\tHeight in centimeters\n\
\t-f\t\tHeight in feet\n\
\t-i\t\tHeight in inches (may be used in conjunction with -f)\n\
\t-n\t\tUse the proposed \"New BMI\" (accounts for short and tall heights)\n\
\t-a\t\tAnalyze BMI qualitatively\n\
\t-h\t\tPrint this help message\n");

}

int
main(int argc, char **argv) {
	if (argc == 1) {
		help();
		return 1;
	}
	double kilograms = 0.0;
	double meters = 0.0;
	int new_bmip = 0;
	int interpretp = 0;
	char c;
	while ((c = getopt(argc, argv, "k:p:c:f:i:nah")) != -1) {
		switch(c) {
		case 'k':
			kilograms += atoi(optarg);
			break;
		case 'p':
			kilograms += lb_to_kg(atoi(optarg));
			break;
		case 'c':
			meters += cm_to_m(atoi(optarg));
			break;
		case 'f':
			meters += ft_to_m(atoi(optarg));
			break;
		case 'i':
			meters += i_to_m(atoi(optarg));
			break;
		case 'n':
			new_bmip = 1;
			break;
		case 'a':
			interpretp = 1;
			break;
		case 'h':
			help();
			break;
		case '?': // indicates where argument does not appear in optstring
			return 1;
		default:
			abort();
		}
	}
	for (int i = optind; i < argc; i++)
		fprintf(stderr, "non-option argument: %s\n", argv[i]);
	if (!kilograms || !meters) {
		fprintf(stderr, "%s: invalid height/mass provided\n", argv[0]);
		return 1;
	}
	float bmi = new_bmip
		? new_bmi(kilograms, meters)
		: old_bmi(kilograms, meters);
	printf("%.1f\n", bmi);
	if (interpretp)
		intepretation(bmi);
	return 0;
}

