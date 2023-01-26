#include <stdio.h>

#define LISTSIZE 10

int swaps;
int comps;

int list[LISTSIZE];

void
swap(int *x, int *y) {
	*x ^= *y;
	*y ^= *x;
 	*x ^= *y;
}

void
carr(int *dest, int *src, int begin, int end) {
	for (int i = 0; i < end; dest[i] = src[i++ - begin]);
}

void
selectsort(int *arr, int sz) {
	int i, j, *max;
	for (i = 0; i < sz - 1; i++) {
		max = arr+i;
		for (j = i + 1; j < sz; j++)
			if (*max < arr[j])
				max = arr + j;
		swap(arr+i, max);
	}
}

void
insertsort(int *arr, int sz) {
	int i, j;
	for (i = 1; i < sz; i++)
		for (j = i; j > 0 && arr[j-1] > arr[j]; j--)
			swap(arr + j, arr + j - 1);
}

void
merge(int *arr, int *tmp, int start, int mid, int end) {
	int l = start, r = mid, i;
	for (i = start; i < end; tmp[i++] = arr[l < mid && (r >= end || arr[l] <= arr[r]) ? l++ : r++]);
}

void
splitmerge(int *arr, int *tmp, int start, int end) {
	if (end - start <= 1)
		return;
	int mid = (end + start) / 2;
	splitmerge(arr, tmp, start, mid);
	splitmerge(arr, tmp, mid, end);
	merge(arr, tmp, start, mid, end);
}

void
mergesort(int *arr, int sz) {
	int tmp[sz];
	carr(arr, tmp, 0, sz);
	splitmerge(arr, tmp, 0, sz);
}


int
pivot(int *arr, int start, int end) {
	int mid = (start + end) / 2;
	if (arr[mid] < arr[start])
		swap(arr + start, arr + mid);
	if (arr[end] < arr[start])
		swap(arr + start, arr + end);
	if (arr[mid] < arr[end])
		swap(arr + mid, arr + end);
	return arr[end];
}

void
quicksort(int *arr, int start, int sz) {
	if (start < sz)
		return;
	int p = pivot(arr, start, sz);
	quicksort(arr, start, p - 1);
	quicksort(arr, p + 1, sz);
}

int
main(int argc, char **argv) {
	list[0] = 10;
	list[2] = 5;
	list[1] = 3;
	for (int i = 0; i < LISTSIZE; i++) {
		printf("%d\n", list[i]);
	}
	putchar('\n');
	selectsort(list, LISTSIZE);
	for (int i = 0; i < LISTSIZE; i++) {
		printf("%d\n", list[i]);
	}
	return 0;
}

