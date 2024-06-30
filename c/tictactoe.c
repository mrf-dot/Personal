#include <stdio.h>

#define DIMENSION 3
#define LL (DIMENSION * 4 - 1)
#define PRCELL(I, J) printf(" %c |", board[(I)][(J)])
char board[DIMENSION][DIMENSION];

void
initboard() {
	for (int i = 0; i < DIMENSION; i++) {
		for (int j = 0; j < DIMENSION; j++) {
			board[i][j] = i+j;
		}
	}
}

void
showboard() {
	for (int i = 0; i < DIMENSION - 1; i++) {
		for (int j = 0; j < DIMENSION - 1; j++) {
			PRCELL(i, j);
		}
		printf("%2c\n", board[i][DIMENSION - 1]);
		for (int j = 0; j < LL; j++)
			putchar('=');
		putchar('\n');
	}
	for (int i = 0; i < DIMENSION - 1; i++) {
		if (!board[i][DIMENSION-1])
			putchar(' ');
		PRCELL(DIMENSION - 1, i);
	}
	printf("%2c\n", board[DIMENSION-1][DIMENSION - 1]);
	putchar('\n');
}

int
winrow(char sign) {
	int i, j, matches;
	for (i = 0; i < DIMENSION; i++) {
		matches = 0;
		for (j = 0; j < DIMENSION; j++) {
			if (board[i][j] == sign)
				matches++;
		}
		if (matches == DIMENSION)
			return 1;
	}
	return 0;
}

int
wincol(char sign) {
	int i, j, matches;
	for (i = 0; i < DIMENSION; i++) {
		matches = 0;
		for (j = 0; j < DIMENSION; j++) {
			if (board[j][i] == sign)
				matches++;
		}
		if (matches == DIMENSION)
			return 1;
	}
	return 0;
}

int
windiag(char sign) {
	int i, matches;
	/* forward */
	matches = 0;
	for (i = 0; i < DIMENSION; i++) {
		if (board[i][i] == sign)
			matches++;
	}
	if (matches == DIMENSION)
		return 1;
	/* backward */
	matches = 0;
	for (i = DIMENSION - 1; i >= 0; i--) {
		if (board[i][DIMENSION - 1 - i] == sign)
			matches++;
	}
	if (matches == DIMENSION)
		return 1;
	return 0;

}

int
iswin(char sign) {
	return winrow(sign) || wincol(sign) || windiag(sign);
}

void
game() {
	showboard();
}

int
main(int argc, char **argv) {
	showboard();
	printf("1 if x is winner: %d\n", iswin('X'));
	board[0][0] = 'X';
	board[1][1] = 'X';
	board[2][2] = 'X';
	showboard();
	printf("1 if x is winner: %d\n", iswin('X'));
	board[1][2] = 'X';
	board[2][0] = 'O';
	board[2][1] = 'O';
	board[2][2] = 'O';
	showboard();
	printf("1 if x is winner: %d\n", iswin('X'));
	return 0;
}

