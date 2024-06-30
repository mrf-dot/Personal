#include <stdio.h>
/* Classical version of printf found in the C reference */

/*
 * Print n in decimal; n must be non-negative
 */
void
printd(int n) {
	int a;
	if (a=n/10)
		printd(a);
	putchar(n % 10 + '0');
}

void
printo(int n) {
	if (n)
		printo((n>>3) &017777);
	putchar((n&07) + '0');
}

void
printf(char fmt[], int *args) {
	char *s;
	struct {char **charpp; };
	struct { double *doublep; };
	int *ap, x, c;
	ap = &args;
	for (;;) {
		while ((c=*fmt++) != '%') {
			if (c == '\0')
				return;
			putchar(c);
		}
		switch (c=*fmt++) {
		/* decimal */
		case 'd':
			x = *ap++;
			if (x < 0) {
				x = -x;
				if (x < 0) { /* is - infinity */
					printf("-32768");
					continue;
				}
				putchar('-');
			}
			printd(x);
			continue;
		/* octal */
		case 'o':
			printo(*ap++);
			continue;
		/* float, double */
		case 'f':
			/* let ftoa do the real work */
			ftoa(*ap.doublep++);
			continue;
		/* character */
		case 'c':
			putchar(*ap++);
			continue;
		/* string */
		case 's':
			s = *ap.charpp++;
			while (c=*s++)
				putchar(c);
			continue;
		}
		putchar(c);
	}
}

