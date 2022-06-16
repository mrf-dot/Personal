#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sodium.h> // Must be compiled with -lsodium as an argument
#include <unistd.h>

#define DECK_SIZE 52
#define BLACKJACK 21
#define ACE_HIGH 11
#define FACE_VAL 10
#define CARD_HEIGHT 7
#define MAX_HAND 5
#define DEALER_MIN 16
#define PAYOUT 1.5
#define UNFLIPPED "\e[0;31m\e[44mXXXXXXXXXX\e[0m"
#define WHITE "\e[0;47m"
#define BLACK_ON_WHITE "\e[0;30m\e[47m"
#define RED_ON_WHITE "\e[0;31m\e[47m"
#define RESET "\e[0m"

char *ranks[] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
char *suites[] = {"♣","♦","♥", "♠"};
int cards[DECK_SIZE];
int cards_size = DECK_SIZE;

void
print_unflipped() {
	fputs(UNFLIPPED, stdout);
	putchar('\t');
}

char *
get_color(int suite) {
	return (suite == 1 || suite == 2) ? RED_ON_WHITE : BLACK_ON_WHITE;
}

char *
get_spaces(int rank) {
	return rank == -1
		? "           "
		: !strcmp(ranks[rank], "10")
		? "         "
		: "          ";
}

int
get_rank(int n) {
	return (n - 1) % (sizeof(ranks) / sizeof(ranks[0]));
}

int
get_suite(int n) {
	return (float) (n - 1) / DECK_SIZE * (sizeof(suites) / sizeof(suites[0]));
}

void
print_footer(int card) {
	if (card == 0) {
		print_unflipped();
	} else {
		int suite = get_suite(card), rank = get_rank(card);
		printf("%s%s%s%s\t", get_color(suite), get_spaces(rank), ranks[rank], RESET);
	}

}

void
print_body(int card) {
	if (card == 0)
		print_unflipped();
	else
		printf("%s%s%s\t", WHITE, get_spaces(-1), RESET);
}

void
print_middle(int card) {
	if (card == 0) {
		print_unflipped();
	} else {
		int suite = get_suite(card);
		printf("%s     %s     %s\t", get_color(suite), suites[suite], RESET);
	}
}

void
print_header(int card) {
	if (card == 0) {
		print_unflipped();
	} else {
		int suite = get_suite(card), rank = get_rank(card);
		printf("%s%s%s%s\t", get_color(suite), ranks[rank], get_spaces(rank), RESET);
	}
}

void
print_hand(int *hand, int lo, int to) {
	putchar('\n');
	int i, j;
	for (i = lo; i < to; print_header(hand[i++]));
	putchar('\n');
	for (i = 0; i < CARD_HEIGHT / 2; i++) {
		for (j = lo; j < to; print_body(hand[j++]));
		putchar('\n');
	}
	for (i = lo; i < to; print_middle(hand[i++]));
	putchar('\n');
	for (i = 0; i < CARD_HEIGHT / 2; i++) {
		for (j = lo; j < to; print_body(hand[j++]));
		putchar('\n');
	}
	for (i = lo; i < to; print_footer(hand[i++]));
	putchar('\n');
	putchar('\n');
}

void
print_cards(int *hand, int size) {
	for (int i = MAX_HAND; i <= size; i += MAX_HAND)
		print_hand(hand, i - MAX_HAND, i);
	int leftover = size % MAX_HAND;
	if (leftover > 0)
		print_hand(hand, size - leftover, size);
}

void
fill_deck() {
	for (int i = 0; i < DECK_SIZE; i++)
		cards[i] = i + 1;
}

void
shuffle_deck() {
	uint32_t i, j, tmp;
	// Fischer-Yates Shuffle
	for (i = DECK_SIZE - 1; i > 0; i--) {
		j = randombytes_uniform(i+1);
		tmp = cards[i];
		cards[i] = cards[j];
		cards[j] = tmp;
	}
}

void
print_deck() {
	print_cards(cards, DECK_SIZE);
}


void
help() {
	printf("CARDS -- Authored by Mitch Feigenbaum\n");
	printf("Options:\n");
	printf("\t-b\t\tPlay an interactive round of Blackjack\n");
	printf("\t-c<n>\t\tPrint a specific card from an ordered deck\n");
	printf("\t-r\t\tPrint a random card\n");
	printf("\t-o\t\tPrint an ordered deck\n");
	printf("\t-s\t\tPrint a random deck.\n");
	printf("\t-h\t\tPrint this help message\n");
}

typedef struct {
	int hand[BLACKJACK];
	int balance;
	int n_cards;
} Gambler;

char
action() {
	printf("[H]it\t[S]tay\t[F]old\t[Q]uit\t");
	char choice;
	while ((choice = getchar()) != 'H'
			&& choice != 'S'
			&& choice != 'F'
			&& choice != 'Q'
			&& choice != 'h'
			&& choice != 's'
			&& choice != 'f'
			&& choice != 'q');
	return choice;
}

int
hand_sum(int *hand, int size) {
	int sum = 0, aces = 0, rank;
	for (int i = 0; i < size; i++) {
		rank = get_rank(hand[i]) + 1;
		sum += (rank > FACE_VAL) ? FACE_VAL : rank;
		aces = aces || rank == 1;
	}
	if (aces && sum + ACE_HIGH - 1 <= BLACKJACK)
		sum += ACE_HIGH - 1;
	return sum;
}

int
get_bet(Gambler *g) {
	printf("Make a bet (balance: %d)\t", g->balance);
	int bet;
	do {
		putchar('$');
		if (!scanf("%d", &bet))
			fputs("Failed to read integer.\n", stderr);
		while(getchar() != '\n');
	} while (bet <= 0 || bet > g->balance);
	g->balance -= bet;
	return bet;
}

void
deal(Gambler *g) {
	g->hand[g->n_cards] = cards[--cards_size];
	g->n_cards++;
}

void
prep_game(Gambler *dealer, Gambler *player) {
	cards_size = DECK_SIZE;
	shuffle_deck();
	dealer->hand[0] = 0;
	dealer->n_cards = 1;
	deal(dealer);
	player->n_cards = 0;
	for (int i = 0; i < 2; i++)
		deal(player);
}

void
show_hands(Gambler *dealer, Gambler *player) {
	puts("\nDealer's hand:");
	print_cards(dealer->hand, dealer->n_cards);
	puts("Player's hand:");
	print_cards(player->hand, player->n_cards);
}

void
contest(Gambler *dealer, Gambler *player, int bet) {
	puts("\nDealer's turn:");
	dealer->hand[0] = cards[--cards_size];
	print_cards(dealer->hand, dealer->n_cards);
	int player_sum = hand_sum(player->hand, player->n_cards);
	int dealer_sum;
	while((dealer_sum = hand_sum(dealer->hand, dealer->n_cards)) < DEALER_MIN && dealer_sum < player_sum) {
		deal(dealer);
		print_cards(dealer->hand, dealer->n_cards);
	}
	if (dealer_sum > BLACKJACK || dealer_sum < player_sum) {
		printf("You win! (+$%d)\n", (int) (bet * PAYOUT - bet));
		bet *= PAYOUT;
		player->balance += bet;
	} else if (dealer_sum == player_sum) {
		player->balance += bet;
		puts("Draw.");
	} else {
		printf("You lose! (-$%d)\n", bet);
	}
}

void
play(Gambler *dealer, Gambler *player, int bet) {
PLAY:
	switch(action()) {
	case 'H':
	case 'h':
		deal(player);
		print_cards(player->hand, player->n_cards);
		if (hand_sum(player->hand, player->n_cards) <= BLACKJACK)
			goto PLAY;
		printf("You've lost this round. (-%d)\n", bet);
		break;
	case 'S':
	case 's':
		contest(dealer, player, bet);
		break;
	case 'F':
	case 'f':
		bet /= 2;
		printf("You've surrendered this round. (-%d)\n", bet);
		player->balance += bet;
		break;
	case 'Q':
	case 'q':
		exit(0);
	default:
		goto PLAY;
		break;
	}
}

void
blackjack() {
	Gambler player = {.balance=100}, bot;
	int bet;
	do {
		bet = get_bet(&player);
		prep_game(&bot, &player);
		show_hands(&bot, &player);
		play(&bot, &player, bet);
	} while (player.balance > 0);
	puts("You've gone bust!");
}

int
main(int argc, char **argv) {
	fill_deck();
	randombytes_stir();
	if (argc == 1) {
		help();
		return 1;
	}
	int c;
	int card;
	while ((c = getopt(argc, argv, "bc:rosh")) != -1)
		switch(c) {
			case 'b':
				blackjack();
				break;
			case 'c':
				card = abs(atoi(optarg));
				if (card > DECK_SIZE) {
					fprintf(stderr, "%s: option -c requires an argument within the range of a standard deck (1-52).\n", argv[0]);
					return 1;
				}
				print_cards(&card, 1);
				break;
			case 'r':
				card = randombytes_uniform(DECK_SIZE) + 1;
				print_cards(&card, 1);
				break;
			case 'o':
				fill_deck();
				print_deck();
				break;
			case 's':
				shuffle_deck();
				print_deck();
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

