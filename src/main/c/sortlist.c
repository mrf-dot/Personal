// Customization variables
//
// Amount of items in the list
#define size 10
// Randomize the list
#define random 1
// Sort the list with bubblesort
#define bubblesort 0
// Sort the list with quicksort
#define quicksort = 1
// Print out each randomization operation
#define randVerbose 1
// Print out each sort operation
#define sortVerbose 1
// Print out each swap
#define swapVerbose 1
// Milliseconds that pass between each operation
#define milliseconds 1000

// Global variables
int swaps = 0;
int operations = 0;
char *yellow = "\[43m";
char *red = "\[41m";
char *green = "\[42m"
int verbose;
int[size] list;

int
main() {
	fill();
}
#ifdef random
		System.out.println("\n\nBegin Randomization.\n");
		boolean tmp = swapVerbose;
		swapVerbose = randVerbose;
		verbose = randVerbose;
		randomize();
		swapVerbose = tmp;
		System.out.printf("%nRandomized List:\t%s%n%n", arrayToString());
#ifdef bubblesort || quicksort
	}
	if (bubblesort || quicksort) {
		System.out.println("Begin Sorting.\n");
		verbose = sortVerbose;
		if (bubblesort)
			bubblesort();
		if (quicksort)
			quicksort();
		System.out.printf("Sorted List:\t%s%nFinished in %d swaps (%d total operations).",
				arrayToString(), swaps, operations );
	}
}
#endif

private static void bubblesort() {
	boolean ordered = true;
	do {
		ordered = true;
		for (int i = 0; i < list.length - 1; i++) {
			operationVerbosity(i, i + 1);
			operations++;
			if (list[i] > list[i + 1]) {
				swap(i, i + 1);
				ordered = false;
				swaps++;
			}
		}
	} while (!ordered);
}

private static void quicksort() {
	quicksort(0, list.length - 1);
}

// Based on the Hoare partition scheme of quicksort
// https://en.wikipedia.org/wiki/Quicksort#Hoare_partition_scheme
private static void quicksort(int start, int stop) {
	if (start >= stop || start < 0 || stop > list.length - 1)
		return;
	int pivot = partition(start, stop);
	quicksort(start, pivot);
	quicksort(pivot + 1, stop);
}

private static int partition(int start, int stop) {
	int pivotIndex = (stop + start) / 2;
	int pivot = list[pivotIndex];
	int leftIndex = start - 1;
	int rightIndex = stop + 1;
	while (true) {
		do {
			leftIndex++;
			operations++;
			operationVerbosity(leftIndex, pivotIndex);
		} while (list[leftIndex] < pivot);
		do {
			rightIndex--;
			operations++;
			operationVerbosity(rightIndex, pivotIndex);
		} while (list[rightIndex] > pivot);
		if (leftIndex >= rightIndex)
			return rightIndex;
		swap(leftIndex, rightIndex);
		operations++;
		swaps++;
	}
}

private static String arrayToString() {
	StringBuilder sb = new StringBuilder();
	for (int i : list)
		sb.append(i).append(' ');
	return sb.toString();
}

private static String arrayToString(int index1, int index2, String color1, String color2) {
	StringBuilder sb = new StringBuilder();
	for (int i = 0; i < list.length; i++)
		sb.append(i == index2 ? color2 : i == index1 ? color1 : "")
				.append(list[i]).append("\u001B[0m ");
	return sb.toString();

}

// Based on the Fischer Yates Algorithm
// https://en.wikipedia.org/wiki/Fisher%E2%80%93Yates_shuffle#The_modern_algorithm
private static void randomize() {
	for (int i = list.length - 1; i > 0; i--) {
		int j = (int) (Math.random() * (i + 1));
		swap(i, j);
	}
}

private static void fill() {
	if (size < 1) {
		System.err.println("Array must be at least 1 value");
		return;
	}
	list = new int[size];
	for (int i = 0; i < size; i++)
		list[i] = i + 1;
}

private static void swap(int index1, int index2) {
	int tmp = list[index1];
	list[index1] = list[index2];
	list[index2] = tmp;
	swapVerbosity(index1, index2);
}

private static void sleep() {
	try {
		Thread.sleep(milliseconds);
	} catch (Exception ex) {
		ex.printStackTrace();
	}
}

public static void swapVerbosity(int index1, int index2) {
	verbosity(index1, index2, green, green, swapVerbose);
}

public static void operationVerbosity(int index1, int index2) {
	verbosity(index1, index2, yellow, red, false);
}

public static void verbosity(int index1, int index2, String color1, String color2, boolean swap) {
	if ((swap && swapVerbose) || verbose) {
		System.out.println(arrayToString(index1, index2, color1, color2));
		sleep();
	}
}
}

