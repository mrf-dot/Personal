/* This program prints all the cards in a standard deck to standard output */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include "csprng.h"

#define DECK_SIZE 52
#define CARD_HEIGHT 7
#define BLACK_ON_WHITE "\e[0;30m\e[47m"
#define RED_ON_WHITE "\e[0;31m\e[47m"
#define RESET "\e[0m"

const char *ranks[] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", };
const char *suites[] = {"♣","♦","♥", "♠"};

void
print_card(int rank, int suite) {
	char *color = suite == 1 || suite == 2 ? RED_ON_WHITE : BLACK_ON_WHITE;
	char *header_spaces = ranks[rank] != "10" ? "         " : "        ";
	printf("\n");
	printf("%s%s%s%s%s\n", color, ranks[rank], header_spaces, suites[suite], RESET);
	char *body_spaces = "           ";
	for (int i = 0; i < CARD_HEIGHT / 2; i++) {
		printf("%s%s%s\n", color, body_spaces, RESET);
	}
	printf("%s     %s     %s\n", color, suites[suite], RESET);
	for (int i = 0; i < CARD_HEIGHT / 2; i++) {
		printf("%s%s%s\n", color, body_spaces, RESET);
	}
	printf("%s%s%s%s%s\n", color, suites[suite],  header_spaces, ranks[rank], RESET);
	printf("\n");
}

void
get_card(int n) {
	n--;
	int rank = n % (sizeof(ranks) / sizeof(ranks[0]));
	int suite = (float) n / DECK_SIZE * (sizeof(suites) / sizeof(suites[0]));
	print_card(rank, suite);
}

void
print_deck() {
	for (int i = 1; i <= DECK_SIZE; i++)
		get_card(i);
}

int *
shuffle(CSPRNG seed) {
	int *cards;
	int i, j, tmp;
	for (i = 0; i < DECK_SIZE; i++)
		cards[i] = i + 1;
	for (i = DECK_SIZE - 1; i >= 0; i--) {
		j = abs(csprng_get_int(seed)) % (i+1);
		tmp = cards[i];
		cards[i] = cards[j];
		cards[j] = tmp;
	}
	return cards;
}

void
shuffle_deck(CSPRNG seed) {
	int *cards = shuffle(seed);
	for (int i = 0; i < DECK_SIZE; i++) {
		printf("%d\n", i);
		get_card(cards[i]);
	}
}


void
help() {
	printf("CARDS -- Authored by Mitch Feigenbaum\n");
	printf("Options:\n");
	printf("\t-c<n>\t\tPrint a specific card from an ordered deck\n");
	printf("\t-r\t\tPrint a random card\n");
	printf("\t-o\t\tPrint an ordered deck\n");
	printf("\t-s\t\tPrint a random deck.\n");
	printf("\t-h\t\tPrint this help message\n");
}

void
blackjack();

int
main(int argc, char **argv) {
	CSPRNG rng = csprng_create(rng);
	if (argc == 1) {
		help();
		return 1;
	}
	int c;
	while ((c = getopt(argc, argv, "c:rosh")) != -1)
		switch(c) {
			case 'c':
				int position = atoi(optarg);
				if (position < 1 || position > DECK_SIZE) {
					fprintf(stderr, "%s: option -c requires an argument within the range of a standard deck (1-52).\n", argv[0]);
					return 1;
				}
				get_card(position);
				break;
			case 'r':
				get_card(abs(csprng_get_int(rng)) % DECK_SIZE + 1);
				break;
			case 'o':
				print_deck();
				break;
			case 's':
				shuffle_deck(rng);
				break;
			case 'h':
				help();
				break;
			case '?':
				return 1;
			default:
				abort();
		}
	for (int i = optind; i < argc; i++)
		fprintf(stderr, "non-option argument: %s\n", argv[i]);
	return 0;
}

