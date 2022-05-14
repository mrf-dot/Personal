#include <stdio.h>

int
main() {
	char q = 34;
	char n = 10;
	char *l[] = {
	"#include <stdio.h>",
	"",
	"int",
	"main() {",
	"	char q = 34;",
	"	char n = 10;",
	"	char *l[] = {",
	"	",
	"	};",
	"	for (int i = 0; i < 7; i++)",
	"		puts(l[i]);",
	"	for (int i = 0; i < sizeof(l) / sizeof(l[0]); i++) {",
	"		fputs(l[7], stdout);",
	"		putchar(q);",
	"		fputs(l[i], stdout);",
	"		putchar(q);",
	"		putchar(',');",
	"		putchar(n);",
	"	}",
	"	for (int i = 8; i < sizeof(l) / sizeof(l[0]); i++)",
	"		puts(l[i]);",
	"}",
	"",
	};
	for (int i = 0; i < 7; i++)
		puts(l[i]);
	for (int i = 0; i < sizeof(l) / sizeof(l[0]); i++) {
		fputs(l[7], stdout);
		putchar(q);
		fputs(l[i], stdout);
		putchar(q);
		putchar(',');
		putchar(n);
	}
	for (int i = 8; i < sizeof(l) / sizeof(l[0]); i++)
		puts(l[i]);
}

