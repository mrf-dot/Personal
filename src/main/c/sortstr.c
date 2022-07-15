#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/random.h>

int swaps = 0, comps = 0;

void
swap(char **a, int i, int j) {
	char *tmp = a[i];
	a[i] = a[j];
	a[j] = tmp;
}

int
partition(char **a, int lo, int to) {
	int pvt = (float) (lo + to) / 2;
	int i, j;
	while(1) {
		for (i = lo; strcasecmp(a[i], a[pvt]) < 0; i++)
			comps++;
		for (j = to; strcasecmp(a[j], a[pvt]) > 0; j--)
			comps++;
		comps++;
		if (i >= j) {
			return j;
		}
		swaps++;
		swap(a, i, j);
	}
}

void
strsort(char **a, int lo, int to) {
	if (lo >= 0 && to >= 0 && lo < to) {
		int p = partition(a, lo, to);
		strsort(a, lo, p);
		strsort(a, p + 1, to);
	}
}

void
shuffle(char **a, int sz) {
	for (int i = sz - 1; i > 0; swap(a, i--, random() % (i+1)));
}

void
prlist(char **a, int sz) {
	for (int i = 0; i < sz; puts(a[i++]));
}

int
main() {
	unsigned int seed;
	if (getrandom(&seed, sizeof seed, GRND_NONBLOCK) == -1) {
		fputs("Randomness could not be obtained.\n", stderr);
		return 1;
	}
	srandom(seed);
	char *dict[] = { "alfa", "bravo", "charlie", "delta", "echo", "foxtrot", "golf", "hotel", "india", "juliett", "kilo", "lima", "mike", "november", "oscar", "papa", "quebec", "romeo", "sierra", "tango", "uniform", "victor", "whiskey", "x-ray", "yankee", "zulu" };
	int sz = sizeof(dict) / sizeof(*dict);
	puts("Before Sorting:\n");
	prlist(dict, sz);
	shuffle(dict, sz);
	puts("\n\nAfter Randomization:\n");
	prlist(dict, sz);
	strsort(dict, 0, sz - 1);
	puts("\n\nAfter Sorting:\n");
	prlist(dict, sz);
	return 0;
}

