#include <stdio.h>

#define DIMENSION 3
#define LL (DIMENSION * 4 - 1)
#define PRCELL(I, J) printf(" %c |", board[(I)][(J)])
char board[DIMENSION][DIMENSION];

void
showboard() {
	for (int i = 0; i < DIMENSION - 1; i++) {
		for (int j = 0; j < DIMENSION - 1; j++) {
			if (!board[i][j])
				putchar(' ');
			PRCELL(i, j);
		}
		printf(" %c\n", board[i][DIMENSION - 1]);
		for (int j = 0; j < LL; j++)
			putchar('=');
		putchar('\n');
	}
	for (int i = 0; i < DIMENSION - 1; i++) {
		if (!board[i][DIMENSION-1])
			putchar(' ');
		PRCELL(DIMENSION - 1, i);
	}
	printf(" %c\n", board[DIMENSION-1][DIMENSION - 1]);
	putchar('\n');
}

void
checkwin();

void
game();

int
main(int argc, char **argv) {
	showboard();
	board[0][0] = 'X';
	board[0][1] = 'X';
	board[0][2] = 'X';
	board[1][0] = 'X';
	board[1][1] = 'X';
	showboard();
	board[1][2] = 'X';
	board[2][0] = 'O';
	board[2][1] = 'O';
	board[2][2] = 'O';
	showboard();
	return 0;
}

