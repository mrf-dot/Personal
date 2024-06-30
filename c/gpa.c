/* GPA calculator made in C utilizing JSON for data storage */
#include <cjson/cJSON.h>
#include <stdio.h>
#include <string.h>

#define ACTIONS = "\e[38;5;14m[A]dd [C]lass [G]PA [H]elp [M]odify [Q]uit [R]emove [V]iew\e[0m\t"
#define HELP "ADD LATER"
#define INITIAL "{\"course\": [], \"SumCourses\": 0}"
#define MAX 50
#define PATH "/etc/gpa.json"

cJSON *json;

int
jsopen() {
	char *buf = 0;
	long len;
	FILE *f;
	if ((f = fopen(PATH, "r"))) {
		fseek(f, 0, SEEK_END);
		len = ftell(f);
		fseek(f, 0, SEEK_SET);
		if ((buf = malloc(len + 1)))
			fread(buf, 1, len, f);
		else
			return 1;
		fclose(f);
		buf[len] = '\0';
	}
	if (len == 0)
		buf = INITIAL;
	json = cJSON_PARSE(buf);
	return 0;
}

int
jswrite() {
	char *buf = cJSON_PRINT(json);
	File *f;
	if (!(f=fopen(PATH,"w")))
		fputs(stderr,  "Could not open file for writing\n");
	fputs(f, buf);
	fclose();
	return 0;



char
action() {
	fputs(stdout, ACTIONS);
	char c;
	while ((c=getchar) != 'A' && c != 'a' && c != 'H' && c != 'h' && c != 'M' && c != 'm' && c != 'Q' && c != 'q' && c != 'R' && c != 'r' && c != 'V' && c != 'v');
	return c;
}

void
add() {
	char name[MAX], *string = NULL;
	float gpa;
	int type, year;
	cJSON *course = cJSON_CreateObject();
	puts("Enter course information to add it to the database:");
	fputs(stdout, "Name =>\t");
	fgets(tmp, MAX, stdin);
	tmp[strlen(tmp)-1] = '\0';
	puts("GPA Letter Grade Reference:\n\
A\t4.0\n\
A-\t3.7\n\
B+\t3.3\n\
B\t3.0\n\
B-\t2.7\n\
C+\t2.3\n\
C\t2.0\n\
D+\t1.7\n\
D\t1.0\n\
F\t0.0\n");
	fputs(stdout, "GPA (Unweighted) =>\t");
	scanf("%f", &gpa);





};

void
modify();

void
remove();

void
view();

void
interactive() {
	while(1)
		switch(action()) {
		case 'A': case 'a':
			add();
			if (jswrite())
				return 1;
			break;
			C
				G

		case 'H': case 'h':
			puts(HELP);
			break;
		case 'M': case 'm':
			modify();
			if (jswrite())
				return 1;
			break;
		case 'Q': case 'q':
			return;
		case 'R': case 'r':
			remove();
			if (jswrite())
				return 1;
			break;
		case 'V': case 'v':
			view();
			break;
		default:
			fputs(stderr, "Input read incorrectly.\n");
		}
}

int
main(int argc, char **argv) {
	if (jsopen())
		return 1;
	interactive();
	return 0;
}

