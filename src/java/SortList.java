/**
 * The {@code SortList} class stores an array of a predefined length
 * containining a sequence of integers. This class is intended to be
 * used for simulation purposes and should not be used in place of
 * predefined list classes such as the {@code ArrayList}. The
 * {@code SortList} class has methods that may be used to randomize
 * a list of sequential elements and sort it using numerous sorting
 * algorithms of varying efficiency. The verbosity of the sorting and
 * randomization can be controlled through the use of boolean global
 * variables.
 *
 * @author Mitch Feigenbaum
 */
public class SortList {
	// Customization variables
	/** Amount of items in the list. */
	private final int SIZE;
	/** Print out each randomization operation. */
	private boolean randVerbose;
	/** Print out each sort operation. */
	private boolean sortVerbose;
	/** Print out each swap. */
	private boolean swapVerbose;
	/** Milliseconds that pass between each operation. */
	private int milliseconds;
	// Global variables
	private int swaps = 0;
	private int operations = 0;
	private boolean verbose;
	private int[] list;
	// Colors
	private static final String YELLOW = "\u001B[43m";
	private static final String RED = "\u001B[41m";
	private static final String GREEN = "\u001B[42m";
	private static final String NONE = "\u001B[0m ";

	/** Initializes the size of the list at 10 elements. */
	public SortList() {
		this(10);
	}

	/**
	 * Initializes the verbosity of the {@code SortList} object at its maximum
	 * value.
	 *
	 * @param SIZE the amount of elements in the list
	 */
	public SortList(int SIZE) {
		this(SIZE, true, true, true, 1000);
	}

	/**
	 * The full constructor for the {@code SortList} class. The constructor allows
	 * for the size of the list to be selected. Additionally the constructor
	 * controls the amout of verbosity given for randomization, sorting, and
	 * swapping. The constructor also fills the list with an ordered sequence of
	 * elements based on the supplied list size.
	 *
	 * @param SIZE         the amount of elements that will be allowed in the list
	 * @param randVerbose  determines if randomization is displayed
	 * @param sortVerbose  determines if the sorting process is displayed
	 * @param swapVerbose  determines if swaps are displayed
	 * @param milliseconds the amount of time (in milliseconds) between each
	 *                     operation
	 */
	public SortList(int SIZE, boolean randVerbose, boolean sortVerbose, boolean swapVerbose, int milliseconds) {
		this.SIZE = SIZE;
		this.randVerbose = randVerbose;
		this.sortVerbose = sortVerbose;
		this.swapVerbose = swapVerbose;
		this.milliseconds = milliseconds;
		fill();
	}

	/** @return the amount of elements in the list */
	public int size() {
		return SIZE;
	}

	/**
	 * @return the total number of actions (swaps and comparisons) taken the last
	 *         time the list was sorted or randomized
	 */
	public int getOperations() {
		return operations;
	}

	/**
	 * @return the number of swaps taken the last time the list was sorted or
	 *         randomized
	 */
	public int getSwaps() {
		return swaps;
	}

	/** @return if verbosity is produced when randomizing the list */
	public boolean getRandVerbose() {
		return randVerbose;
	}

	/** @return if verbosity is produced when sorting the list */
	public boolean getSortVerbose() {
		return sortVerbose;
	}

	/** @return if verbosity is produced when swapping elements of the list */
	public boolean getSwapVerbose() {
		return swapVerbose;
	}

	/** @return the amount of time (in milliseconds) between each operation */
	public int getMilliseconds() {
		return milliseconds;
	}

	/**
	 * Changes the verbosity when randomizing the list.
	 *
	 * @param randVerbose determines if randomization is displayed
	 */
	public void setRandVerbose(boolean randVerbose) {
		setVerbose(randVerbose, sortVerbose, swapVerbose);
	}

	/**
	 * Changes the verboisty when sorting the list.
	 *
	 * @param sortVerbose determines if the sorting process is displayed
	 */
	public void setSortVerbose(boolean sortVerbose) {
		setVerbose(randVerbose, sortVerbose, swapVerbose);
	}

	/**
	 * Changes the verbosity when swaps are performed on the list.
	 *
	 * @param swapVerbose determines if swaps are displayed
	 */
	public void setSwapVerbose(boolean swapVerbose) {
		setVerbose(randVerbose, sortVerbose, swapVerbose);
	}

	/**
	 * Sets all three verbosity variables that control the amount of output given
	 * when performing actions on the list.
	 *
	 * @param randVerbose determines if randomization is displayed
	 * @param sortVerbose determines if the sorting process is displayed
	 * @param swapVerbose determines if swaps are displayed
	 */
	public void setVerbose(boolean randVerbose, boolean sortVerbose, boolean swapVerbose) {
		this.randVerbose = randVerbose;
		this.sortVerbose = sortVerbose;
		this.swapVerbose = swapVerbose;
	}

	/**
	 * Turns the verbosity for all actions performed on the list either on or off
	 * based on a boolean supplied as an argument.
	 *
	 * @param verbose determines whether verbosity is turned on or off
	 */
	public void toggleVerbose(boolean verbose) {
		if (verbose) {
			randVerbose = true;
			sortVerbose = true;
			swapVerbose = true;
		} else {
			randVerbose = false;
			sortVerbose = false;
			swapVerbose = false;
		}
	}

	/**
	 * Sets the amount of time (in milliseconds) between each displayed list
	 * operation.
	 *
	 * @param milliseconds the amount of time (in milliseconds) between each
	 */
	public void setMilliseconds(int milliseconds) {
		this.milliseconds = milliseconds;
	}

	/**
	 * Displays in a verbose manner both the randomization and sorting of the list.
	 * While the randomization of the list is always done with the Fischer Yates
	 * method, the sorting algorithm is determined with an argument with the name
	 * of the algorithm in String form.
	 *
	 * @param sortMethod the algorithm used to sort the list
	 * @see showRandom
	 * @see showSort
	 */
	public void fullSort(String sortMethod) {
		showRandom();
		showSort(sortMethod);
	}

	/**
	 * Shows the randomization of the list in a verbose mannner.
	 *
	 * @see randomize
	 */
	public void showRandom() {
		System.out.println("\n\nBegin Randomization.\n");
		boolean tmp = swapVerbose;
		swapVerbose = randVerbose;
		verbose = randVerbose;
		randomize();
		swapVerbose = tmp;
		System.out.printf("%nRandomized List:\t%s%n%n", arrayToString());
	}

	/**
	 * Shows the sorting of the list in a verbose manner. The algorithm used to sort
	 * the list is chosen with a string argument. The following options are
	 * available:
	 *
	 * <dl>
	 * <dt>"bubble"</dt>
	 * <dd>Bubble Sort</dd>
	 * <dt>"insert"</dt>
	 * <dd>Insertion Sort</dd>
	 * <dt>"mitch"</dt>
	 * <dd>A modified bubble sort that works until it reaches the end of the
	 * list</dd>
	 * <dt>"quick"</dt>
	 * <dd>Quicksort</dd>
	 * </dl>
	 *
	 * @param sortMethod the algorithm used to sort the list
	 * @see bubblesort
	 * @see insertsort
	 * @see mitchsort
	 * @see quicksort
	 */
	public void showSort(String sortMethod) {
		System.out.println("Begin Sorting.\n");
		verbose = sortVerbose;
		switch (sortMethod) {
			case "bubble":
				bubblesort();
				break;
			case "insert":
				insertsort();
				break;
			case "mitch":
				mitchsort();
				break;
			default:
				quicksort();

		}
		System.out.printf("Sorted List:\t%s%nFinished in %d swaps and %d comparisons.%n%n",
				arrayToString(), swaps, operations - swaps);
	}

	public String toString() {
		return String.format("List:\t\t\t\t%s%n"
				+ "Size:\t\t\t\t%d%n"
				+ "Swaps:\t\t\t\t%d%n"
				+ "Comparisons:\t\t\t%d%n"
				+ "Verbose Randomization:\t\t%s%n"
				+ "Verbose Sorting:\t\t%s%n"
				+ "Verbose Swapping:\t\t%s%n"
				+ "Time between Operations:\t%d%n",
				arrayToString(), SIZE, swaps, operations - swaps, randVerbose, sortVerbose, swapVerbose,
				milliseconds);
	}

	/** Sorts the list with the Bubble Sort algorithm. */
	public void bubblesort() {
		clearStats();
		boolean ordered;
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

	/** Sorts the list with the Insertion Sort algorithm. */
	public void insertsort() {
		clearStats();
		for (int i = 1; i < SIZE; i++)
			for (int j = i; j > 0 && list[j - 1] > j; j--) {
				operationVerbosity(j - 1, j);
				swap(j, j - 1);
			}

	}

	/**
	 * Sorts the list with a modified version of the Bubble Sort algorithm. This
	 * algorithm acts like Bubble Sort but goes to the zeroeth index of the list
	 * every time a swap is performed. It generally performs worse than a
	 * traditional Bubble Sort algorithm.
	 */
	public void mitchsort() {
		clearStats();
		for (int i = 0; i < list.length - 1; i++) {
			operationVerbosity(i, i + 1);
			if (list[i] > list[i + 1]) {
				swap(i, i + 1);
				i = -1;
			}
		}
	}

	/**
	 * Based on the Hoare partition scheme of quicksort.
	 *
	 * @see <a href=
	 *      "https://wikipedia.org/wiki/Quicksort#Hoare_partition_scheme">Hoare
	 *      Partitioning Scheme</a>
	 */
	public void quicksort() {
		clearStats();
		quicksort(0, list.length - 1);
	}

	/**
	 * Based on the Hoare partition scheme of quicksort.
	 *
	 * @param start the index of the portion of the list to be sorted
	 * @param stop  the ending index of the portion of the list to be sorted
	 * @see partition
	 */
	private void quicksort(int start, int stop) {
		if (start >= 0 && stop >= 0 && start < stop) {
			int pivot = partition(start, stop);
			quicksort(start, pivot);
			quicksort(pivot + 1, stop);
		}
	}

	private int partition(int start, int stop) {
		int pivotIndex = (stop + start) / 2;
		int pivot = list[pivotIndex];
		int leftIndex = start - 1;
		int rightIndex = stop + 1;
		while (true) {
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

	public SortList copy() {
		return new SortList(SIZE, randVerbose, sortVerbose, swapVerbose, milliseconds);
	}

	private String arrayToString() {
		StringBuilder sb = new StringBuilder();
		for (int i : list)
			sb.append(i).append(' ');
		return sb.toString();
	}

	private String arrayToString(int index1, int index2, String color1, String color2) {
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < list.length; i++)
			sb.append(i == index2
					? color2
					: i == index1
							? color1
							: "")
					.append(list[i]).append(NONE);
		return sb.toString();

	}

	// Based on the Fischer Yates Algorithm
	// https://en.wikipedia.org/wiki/Fisher%E2%80%93Yates_shuffle#The_modern_algorithm
	public void randomize() {
		clearStats();
		for (int i = list.length - 1; i > 0; i--) {
			int j = (int) (Math.random() * (i + 1));
			swap(i, j);
		}
	}

	public void fill() {
		if (SIZE < 1) {
			System.err.println("Array must be at least 1 value");
			return;
		}
		list = new int[SIZE];
		for (int i = 0; i < SIZE; i++)
			list[i] = i + 1;
	}

	private void swap(int index1, int index2) {
		int tmp = list[index1];
		list[index1] = list[index2];
		list[index2] = tmp;
		swapVerbosity(index1, index2);
	}

	/**
	 * Pauses program execution for the amount of milliseconds specified in the
	 * {@code milliseconds} variable
	 */
	private void sleep() {
		if (milliseconds > 0)
			try {
				Thread.sleep(milliseconds);
			} catch (Exception ex) {
				ex.printStackTrace();
			}
	}

	private void swapVerbosity(int index1, int index2) {
		swaps++;
		verbosity(index1, index2, GREEN, GREEN, swapVerbose);
	}

	private void operationVerbosity(int index1, int index2) {
		verbosity(index1, index2, YELLOW, RED, false);
	}

	private void verbosity(int index1, int index2, String color1, String color2, boolean swap) {
		operations++;
		if ((swap && swapVerbose) || verbose) {
			System.out.println(arrayToString(index1, index2, color1, color2));
			sleep();
		}
	}

	/** Initializes the {@code operations} and {@code swaps} counter variables */
	private void clearStats() {
		operations = 0;
		swaps = 0;
	}

	public static void main(String[] args) {
		// int SIZE, boolean randVerbose, boolean sortVerbose, boolean swapVerbose, int milliseconds
		SortList sl1 = new SortList(10, true, true, true, 100);
		System.out.println(sl1);
		// bubble, insert, mitch, quick
		sl1.fullSort("insert");
	}
}
