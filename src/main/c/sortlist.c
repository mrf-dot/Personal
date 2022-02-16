#include <stdio.h>
#include "sortlist.h"

int current_random = 0;
int verbose;
int[SIZE] list = fill();


#if BUBBLESORT
void bubblesort() {
	int ordered = 1;
	do {
		ordered = 1;
		for (int i = 0; i < list.length - 1; i++) {
			op_verbose(i, i + 1);
			if (list[i] > list[i + 1]) {
				swap(i, i + 1);
				ordered = 0;
			}
		}
	} while (!ordered);
}
#endif

// Based on the Hoare partition scheme of quicksort
// https://en.wikipedia.org/wiki/Quicksort#Hoare_partition_scheme
#if QUICKSORT
void quicksort(int start, int stop) {
	if (start >= 0 && stop >= 0 && start < stop) {
		int p = partition(start, stop);
		quicksort(start, p);
		quicksort(p + 1, stop);
	}
}

int partition(int start, int stop) {
	int pindex = (stop + start) / 2;
	int p = list[pindex];
	int left = start - 1;
	int right = stop + 1;
	while (1) {
		do {
			left++;
			op_verbose(left, pindex);
		} while (list[left] < p);
		do {
			right--;
			op_verbose(right, pindex);
		} while (list[right] > p);
		if (left >= right)
			return right;
		swap(left, right);
	}
}
#endif

void *prlist() {
	for (int i = 0; i < sizeof(list), i++)
		printf("%d ", list[i]);
}

void prclist(int i1, int i2, char *c1, char *c2) {
	char *ccolor;
	for (int i = 0; i < list.length; i++) {
		ccolor = i == i2 ? c2 : i == i1 ? c1 : "";
		printf("%s%d%s ", ccolor, list[i], color.none);
	}

}

// Based on the Fischer Yates Algorithm
// https://en.wikipedia.org/wiki/Fisher%E2%80%93Yates_shuffle#The_modern_algorithm
#if RANDOM
void randomize() {
	for (int i = list.length - 1; i > 0; i--) {
		int j = (int) (Math.random() * (i + 1));
		swap(i, j);
	}
}

void random() {
	printf("\n\nBegin Randomization.\n");
	current_random = 1
	verbose = RANDVERBOSE;
	randomize();
	current_random = 0
	printf("\nRandomized List:\t");
	prlist();
	printf("\n\n");
}
#endif

void fill() {
	if (sizeof(list) > 0)
		for (int i = 0; i < sizeof(list); i++)
			list[i] = i + 1;
}

void swap(int i1, int i2) {
	int tmp = list[i1];
	list[i1] = list[i2];
	list[i2] = tmp;
	swap_verbose(i1, i2);
}

void swap_verbose(int i1, int i2) {
	swaps++;
	verbose(i1, i2, green, green, swapVerbose);
}

void op_verbose(int i1, int i2) {
	verbose(i1, i2, Colors.yellow, Colors.red, 0);
}

void verbose(int i1, int i2, *c1, String c2, int swap) {
	operations++;
	if ((swap && swapVerbose) || verbose) {
		prclist(i1, i2, c1, c2);
		usleep(milliseconds);
	}
}

void sort() {
	printf("Begin Sorting.\n");
	if (BUBBLESORT)
		bubblesort();
	if (QUICKSORT)
		quicksort(0, sizeof(list) - 1);
	printf("Sorted List:\t");
	prlist();
	printf("\nFinished in %d swaps (%d total operations).", Operations.swaps, Operations.operations);
}

int main() {
	if (RANDOM)
		random();
	if (QUICKSORT || BUBBLESORT)
		sort();
}

