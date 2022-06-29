#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sodium.h> // Must be compiled with -lsodium as an argument
#include <unistd.h>

#define ACEHIGH 11
#define BLACKJACK 21
#define BLACKONWHITE "\e[0;30m\e[47m"
#define CARDHEIGHT 7
#define DEALERMIN 16
#define DECKSIZE 52
#define FACEVAL 10
#define HELP "CARDS -- Authored by Mitch Feigenbaum\n\
Options:\n\
\t-b\t\tPlay an interactive round of Blackjack\n\
\t-c<n>\t\tPrint a specific card from an ordered deck\n\
\t-r\t\tPrint a random card\n\
\t-o\t\tPrint an ordered deck\n\
\t-s\t\tPrint a random deck.\n\
\t-h\t\tPrint this help message\n"
#define MAXHAND 5
#define PAYOUT 1.5
#define REDONWHITE "\e[0;31m\e[47m"
#define RESET "\e[0m"
#define UNFLIPPED "\e[0;31m\e[44mXXXXXXXXXX\e[0m\t"
#define WHITE "\e[0;47m"

const char *RANKS[] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
const char *SUITES[] = {"♣","♦","♥", "♠"};
int cards[DECKSIZE];
int cardssize = DECKSIZE;
typedef struct {
	int hand[BLACKJACK];
	int balance;
	int ncards;
} Gambler;

#define COLOR(SUITE) (((SUITE) == 1 || (SUITE) == 2) ? REDONWHITE : BLACKONWHITE)
#define DEAL(G) (G->hand[G->ncards++] = cards[--cardssize])
#define FILL() for (int i = 0; i < DECKSIZE; cards[i-1] = ++i)
#define GETRANK(POS) (((POS) - 1) % (sizeof(RANKS) / sizeof(RANKS[0])))
#define GETSUITE(POS) ((int) ((float) ((POS) - 1) / DECKSIZE * (sizeof(SUITES) / sizeof(SUITES[0]))))
#define SPACES(RANK) (((RANK) == -1) ?  "           " : !strcmp(RANKS[(RANK)], "10") ? "         " : "          ")

void
print_footer(int card) {
	if (card == 0) {
		fputs(UNFLIPPED, stdout);
	} else {
		int suite = GETSUITE(card), rank = GETRANK(card);
		printf("%s%s%s%s\t", COLOR(suite), SPACES(rank), RANKS[rank], RESET);
	}

}

void
print_body(int card) {
	if (card == 0)
		fputs(UNFLIPPED, stdout);
	else
		printf("%s%s%s\t", WHITE, SPACES(-1), RESET);
}

void
print_middle(int card) {
	if (card == 0) {
		fputs(UNFLIPPED, stdout);
	} else {
		int suite = GETSUITE(card);
		printf("%s     %s     %s\t", COLOR(suite), SUITES[suite], RESET);
	}
}

void
print_header(int card) {
	if (card == 0) {
		fputs(UNFLIPPED, stdout);
	} else {
		int suite = GETSUITE(card), rank = GETRANK(card);
		printf("%s%s%s%s\t", COLOR(suite), RANKS[rank], SPACES(rank), RESET);
	}
}

void
print_hand(int *hand, int lo, int to) {
	putchar('\n');
	int i, j;
	for (i = lo; i < to; print_header(hand[i++]));
	putchar('\n');
	for (i = 0; i < CARDHEIGHT / 2; i++) {
		for (j = lo; j < to; print_body(hand[j++]));
		putchar('\n');
	}
	for (i = lo; i < to; print_middle(hand[i++]));
	putchar('\n');
	for (i = 0; i < CARDHEIGHT / 2; i++) {
		for (j = lo; j < to; print_body(hand[j++]));
		putchar('\n');
	}
	for (i = lo; i < to; print_footer(hand[i++]));
	putchar('\n');
	putchar('\n');
}

void
print_cards(int *hand, int size) {
	int leftover = size % MAXHAND;
	for (int i = 0; i < size - leftover; print_hand(hand, i - MAXHAND, i += MAXHAND));
	if (leftover > 0)
		print_hand(hand, size - leftover, size);
}

void
shuffle_deck() {
	unsigned int i, j, tmp;
	/* Fischer-Yates Shuffle */
	for (i = DECKSIZE - 1; i > 0; i--) {
		j = randombytes_uniform(i+1);
		tmp = cards[i];
		cards[i] = cards[j];
		cards[j] = tmp;
	}
}

char
action() {
	printf("[H]it\t[S]tay\t[F]old\t[Q]uit\t");
	char choice;
	while ((choice = getchar()) != 'H' && choice != 'S' && choice != 'F' && choice != 'Q' && choice != 'h' && choice != 's' && choice != 'f' && choice != 'q');
	return choice;
}

int
hand_sum(int *hand, int size) {
	int sum = 0, aces = 0, rank;
	for (int i = 0; i < size; i++) {
		sum += ((rank = GETRANK(hand[i]) + 1) > FACEVAL) ? FACEVAL : rank;
		aces = aces || rank == 1;
	}
	return aces && sum + ACEHIGH - 1 <= BLACKJACK ? sum + ACEHIGH - 1 : sum;
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
prep_game(Gambler *dealer, Gambler *player) {
	cardssize = DECKSIZE;
	shuffle_deck();
	dealer->hand[0] = 0;
	dealer->ncards = 1;
	DEAL(dealer);
	player->ncards = 0;
	for (int i = 0; i < 2; i++)
		DEAL(player);
}

void
show_hands(Gambler *dealer, Gambler *player) {
	puts("\nDealer's hand:");
	print_cards(dealer->hand, dealer->ncards);
	puts("Player's hand:");
	print_cards(player->hand, player->ncards);
}

void
contest(Gambler *dealer, Gambler *player, int bet) {
	puts("\nDealer's turn:");
	dealer->hand[0] = cards[--cardssize];
	print_cards(dealer->hand, dealer->ncards);
	int player_sum = hand_sum(player->hand, player->ncards);
	int dealer_sum;
	while((dealer_sum = hand_sum(dealer->hand, dealer->ncards)) < DEALERMIN && dealer_sum < player_sum) {
		DEAL(dealer);
		print_cards(dealer->hand, dealer->ncards);
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
		case 'H': case 'h':
			DEAL(player);
			print_cards(player->hand, player->ncards);
			if (hand_sum(player->hand, player->ncards) <= BLACKJACK)
				goto PLAY;
			printf("You've lost this round. (-%d)\n", bet);
			break;
		case 'S': case 's':
			contest(dealer, player, bet);
			break;
		case 'F': case 'f':
			bet /= 2;
			printf("You've surrendered this round. (-%d)\n", bet);
			player->balance += bet;
			break;
		case 'Q': case 'q':
			exit(0);
		default:
			goto PLAY;
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
	if (argc == 1) {
		fputs(HELP, stderr);
		return 1;
	}
	FILL();
	randombytes_stir();
	int c;
	int card;
	while ((c = getopt(argc, argv, "bc:rosh")) != -1)
		switch(c) {
			case 'b':
				blackjack();
				break;
			case 'c':
				card = abs(atoi(optarg));
				if (card > DECKSIZE) {
					fprintf(stderr, "%s: option -c requires an argument within the range of a standard deck (1-52).\n", argv[0]);
					return 1;
				}
				print_cards(&card, 1);
				break;
			case 'r':
				card = randombytes_uniform(DECKSIZE) + 1;
				print_cards(&card, 1);
				break;
			case 'o':
				FILL();
				print_cards(cards, DECKSIZE);
				break;
			case 's':
				shuffle_deck();
				print_cards(cards, DECKSIZE);
				break;
			case 'h':
				fputs(HELP, stdout);
				break;
			case '?':
				return 1;
			default:
				abort();
		}
	for (int i = optind; i < argc; fprintf(stderr, "non option argument: %s\n", argv[i++]));
	return 0;
}

