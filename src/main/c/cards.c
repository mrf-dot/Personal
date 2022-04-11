/* This program prints all the cards in a standard deck to standard output */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define GRAPHIC
#define DECK_SIZE 52
#define CARD_HEIGHT 7
#define BLACK_ON_WHITE "\e[0;30m\e[47m"
#define RED_ON_WHITE "\e[0;31m\e[47m"
#define RESET "\e[0m"

const char *ranks[] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", };
const char *suites[] = {"Clubs", "Diamonds", "Hearts", "Spades"};
const char *symbols[] = {"♣","♥","♦","♠"};

void
print_card(int rank, int suite) {
#ifdef GRAPHIC
	char *color = suite == 1 || suite == 2 ? RED_ON_WHITE : BLACK_ON_WHITE;
	char *header_spaces = ranks[rank] != "10" ? "         " : "        ";
	printf("\n");
	printf("%s%s%s%s%s\n", color, ranks[rank], header_spaces, symbols[suite], RESET);
	char *body_spaces = "           ";
	for (int i = 0; i < CARD_HEIGHT / 2; i++) {
		printf("%s%s%s\n", color, body_spaces, RESET);
	}
	printf("%s     %s     %s\n", color, symbols[suite], RESET);
	for (int i = 0; i < CARD_HEIGHT / 2; i++) {
		printf("%s%s%s\n", color, body_spaces, RESET);
	}
	printf("%s%s%s%s%s\n", color, symbols[suite],  header_spaces, ranks[rank], RESET);
	printf("\n");
#else
	printf("%s of %s\n", ranks[rank], suites[suite]);
#endif
}

void
get_card(int n) {
	n--;
	if (n > DECK_SIZE || n < 0)
		return;
	int rank = n % (sizeof(ranks) / sizeof(ranks[0]));
	int suite = (float) n / DECK_SIZE * (sizeof(suites) / sizeof(suites[0]));
	print_card(rank, suite);
}

void
print_deck() {
	for (int i = 1; i <= DECK_SIZE; i++)
		get_card(i);
}

void
rand_card() {
	get_card(random() % DECK_SIZE + 1);
}

void
shuffle_deck() {
	int cards[DECK_SIZE];
	int i, j, tmp;
	for (i = 1; i <= DECK_SIZE; i++)
		cards[i-1] = i;
	// Fischer Yates Shuffle
	for (i = DECK_SIZE-1; i > 0; i--) {
		j = random() % (i + 1);
		tmp = cards[i];
		cards[i] = cards[j];
		cards[j] = tmp;
		printf("%d and %d swapped.\n", i, j);
	}
	for (int i = 0; i < DECK_SIZE; i++)
		get_card(cards[i]);
}

int
main(int argc, char *argv[]) {
	srandom(time(0));
	switch(getopt(argc, argv, "c:rosh")) {
		case 'c':
			get_card(atoi(optarg));
			return 0;
		case 'r':
			rand_card();
			return 0;
		case 'o':
			print_deck();
			return 0;
		case 's':
			shuffle_deck();
			return 0;
		case '?':
		case 'h':
		default:
			printf("CARDS -- Authored by Mitch Feigenbaum\n");
			printf("Options:\n");
			printf("\t-c<n>\t\tPrint a specific card from an ordered deck\n");
			printf("\t-r\t\tPrint a random card\n");
			printf("\t-o\t\tPrint an ordered deck\n");
			printf("\t-s\t\tPrint a random deck.\n");
			printf("\t-h\t\tPrint this help message\n");
			return 0;
	}
}

