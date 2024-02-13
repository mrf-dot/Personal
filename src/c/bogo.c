#include <stdio.h>
#include <stdlib.h>

// executes in-place bogo sort on a given array
static void bogo_sort(int* a, int size);
// returns 1 if given array is sorted and 0 otherwise
static int is_sorted(int* a, int size);
// shuffles the given array into a random order
static void shuffle(int* a, int size);

void bogo_sort(int* a, int size) {
    while (!is_sorted(a, size)) {
        shuffle(a, size);
    }
}

int is_sorted(int* a, int size) {
    for (int i = 0; i < size-1; i++) {
        if (a[i] > a[i+1]) {
            return 0;
        }
    }
    return 1;
}

void shuffle(int* a, int size) {
    int temp, random;
    for (int i = 0; i < size; i++) {
        random = (int) ((double) rand() / ((double) RAND_MAX + 1) * size);
        temp = a[random];
        a[random] = a[i];
        a[i] = temp;
    }
}

int main() {
    // example usage
    int input[] = {2, 1, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17,
    18, 19, 20};
    int size = sizeof(input) / sizeof(*input);

    bogo_sort(input, size);

    // sorted result: 14 45 65 67 68 74 78 78 87 89 90 98
    printf("sorted result:");
    for (int i = 0; i < size; i++) {
        printf(" %d", input[i]);
    }
    printf("\n");

    return 0;
}

