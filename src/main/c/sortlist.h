// Amount of items in the list
#define SIZE	10
// Randomize the list
#define RANDOM	1
// Sort the list with bubblesort
#define BUBBLESORT	1
// Sort the list with quicksort
#define QUICKSORT	1
// Print out each randomization operation
#define RANDVERBOSE	1
// Print out each sort operation
#define SORTVERBOSE	1
// Print out each swap
#define SWAPVERBOSE	1
// Milliseconds that pass between each operation
#define MILLISECONDS	1000

const struct Operations {
	int swaps;
	int operations;
};
const struct Colors {
	char *yellow;
	char *red;
	char *green;
	char *none;
};

const struct Colors colors = {"\[43m", "\[41m", "\[42m", "\[0m"};
struct Operations operations = {0, 0};

