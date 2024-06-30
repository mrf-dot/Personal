#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define COLS 7
#define ROWS 6
#define REPLEN 3
#define C1 "\033[31mRd\033[0m"
#define C2 "\033[33mYe\033[0m"

char board[ROWS][COLS][20];

void
fill() {
	char tmp[REPLEN];
	tmp[REPLEN] = '\0';
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			tmp[0] = 'a' + i;
			tmp[1] = '0' + j;
			strcpy(board[i][j], tmp);
		}
	}
}

void
prboard() {
	putchar('\n');
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			putchar('|');
			fputs(board[i][j], stdout);
		}
		fputs("|\n", stdout);
		for (int k = 0; k <= COLS * REPLEN; k++)
			putchar('=');
		putchar('\n');
	}
	putchar('\n');
}

int
isvalid(char *pos) {
	return pos[0] > 'A' && pos[0] < 'A' + COLS && pos[1] - '0' > 0 && pos[1] - '0' < ROWS && strcmp(board[pos[0] - 'A'][pos[1] - '0'], pos) == 'a' - 'A';
}

void
fillpos(char sel[], char *color) {
	if (sel[0] > 'a')
		sel[0] = sel[0] - 'a' + 'A';
	if (isvalid(sel)
	strcpy(board[sel[0] - 'A'][sel[1] - '0'], C1);
}

int
main(int argc, char **argv) {
	fill();
	prboard();
	char pos[] = "E6";
	if (!isvalid(pos))
	printf("Invalid cell %s selected. Please input a valid cell.\n", pos);
	fillpos(pos, C1);
	prboard();
	fillpos(pos, C1);
	prboard();
	return 0;
}

