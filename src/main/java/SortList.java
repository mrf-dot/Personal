public class SortList {
	// Customization variables
	//
	// Amount of items in the list
	private static final int size = 10;
	// Randomize the list
	private static final boolean random = true;
	// Sort the list with bubblesort
	private static final boolean bubblesort = false;
	// Sort the list with quicksort
	private static final boolean quicksort = true;
	// Sort the list with quicksort
	// Print out each randomization operation
	private static final boolean randVerbose = true;
	// Print out each sort operation
	private static final boolean sortVerbose = true;
	// Print out each swap
	private static boolean swapVerbose = true;
	// Milliseconds that pass between each operation
	private static final int milliseconds = 1000;

	// Global variables
	private static int swaps = 0;
	private static int operations = 0;
	private static final String yellow = "\u001B[43m";
	private static final String red = "\u001B[41m";
	private static final String green = "\u001B[42m";
	private static boolean verbose;
	private static int[] list;

	public static void main(String[] args) {
		fill();
		if (random) {
			System.out.println("\n\nBegin Randomization.\n");
			boolean tmp = swapVerbose;
			swapVerbose = randVerbose;
			verbose = randVerbose;
			randomize();
			swapVerbose = tmp;
			System.out.printf("%nRandomized List:\t%s%n%n", arrayToString());
		}
		if (bubblesort || quicksort) {
			swaps = 0;
			operations = 0;
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

	private static void bubblesort() {
		boolean ordered = true;
		do {
			ordered = true;
			for (int i = 0; i < list.length - 1; i++) {
				operationVerbosity(i, i + 1);
				if (list[i] > list[i + 1]) {
					swap(i, i + 1);
					ordered = false;
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
		if (start >= 0 && stop >= 0 && start < stop) {
			int pivot = partition(start, stop);
			quicksort(start, pivot);
			quicksort(pivot + 1, stop);
		}
	}

	private static int partition(int start, int stop) {
		int pivotIndex = (stop + start) / 2;
		int pivot = list[pivotIndex];
		int leftIndex = start - 1;
		int rightIndex = stop + 1;
		for (;;) {
			do {
				leftIndex++;
				operationVerbosity(leftIndex, pivotIndex);
			} while (list[leftIndex] < pivot);
			do {
				rightIndex--;
				operationVerbosity(rightIndex, pivotIndex);
			} while (list[rightIndex] > pivot);
			if (leftIndex >= rightIndex)
				return rightIndex;
			swap(leftIndex, rightIndex);
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
		swaps++;
		verbosity(index1, index2, green, green, swapVerbose);
	}

	public static void operationVerbosity(int index1, int index2) {
		verbosity(index1, index2, yellow, red, false);
	}

	public static void verbosity(int index1, int index2, String color1, String color2, boolean swap) {
		operations++;
		if ((swap && swapVerbose) || verbose) {
			System.out.println(arrayToString(index1, index2, color1, color2));
			sleep();
		}
	}
}
