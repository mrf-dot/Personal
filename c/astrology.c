#include <stdio.h>
#include <time.h>

void
birthdate(int m, int d) {
	char *months[] = {
		"January",
		"February",
		"March",
		"April",
		"May",
		"June",
		"July",
		"August",
		"September",
		"October",
		"November",
		"December",
	};
	char *ordinal[] = {
		"first",
		"second",
		"third",
		"fourth",
		"fifth",
		"sixth",
		"seventh",
		"eighth",
		"ninth",
		"tenth",
		"eleventh",
		"twelfth",
		"thirteenth",
		"fourteenth",
		"fifteenth",
		"sixteenth",
		"seventeenth",
		"eighteenth",
		"nineteenth",
		"twentieth",
		"twenty-first",
		"twenty-second",
		"twenty-third",
		"twenty-fourth",
		"twenty-fifth",
		"twenty-sixth",
		"twenty-seventh",
		"twenty-eighth",
		"twenty-ninth",
		"thirtieth",
		"thirty-first",
	};
	printf("%s %s", months[m - 1], ordinal[d-1]);
}

void
sign(int m, int d) {
	printf(
		(m == 1 && d >= 20) || (m == 2 && d <= 18)
		? "Your sign is:\t\tAquarius\nHoroscope:\t\tYou must hold back your desires and temptations."
		: (m == 2 && d >= 19) || (m == 3 && d <= 20)
		? "Your sign is:\t\tPisces\nHoroscope:\t\tSoon you will make amends with all you have wronged."
		: (m == 3 && d >= 21) || (m == 4 && d <= 19)
		? "Your sign is:\t\tAries\nHoroscope:\t\tYour home planet will be destroyed."
		: (m == 4 && d >= 20) || (m == 5 && d <= 20)
		? "Your sign is:\t\tTaurus\nHoroscope:\t\tHave faith in the plan."
		: (m == 5 && d >= 21) || (m == 6 && d <= 20)
		? "Your sign is:\t\tGemini\nHoroscope:\t\tThe best days of your life are already over."
		: (m == 6 && d >= 21) || (m == 7 && d <= 22)
		? "Your sign is:\t\tCancer\nHoroscope:\t\tYou will hold back your own success."
		: (m == 7 && d >= 23) || (m == 8 && d <= 22)
		? "Your sign is:\t\tLeo\nHoroscope:\t\tYou will achieve great success in the textile industry."
		: (m == 8 && d >= 23) || (m == 9 && d <= 22)
		? "Your sign is:\t\tVirgo\nHoroscope:\t\tThere is light at the end of your sorrow."
		: (m == 9 && d >= 23) || (m == 10 && d <= 22)
		? "Your sign is:\t\tLibra\nHoroscope:\t\tTerrible things are going to happen."
		: (m == 10 && d >= 23) || (m == 11 && d <= 21)
		? "Your sign is:\t\tScorpio\nHoroscope:\t\tYour days are numbered. Keep watch of all enemies."
		: (m == 11 && d >= 22) || (m == 12 && d <= 21)
		? "Your sign is:\t\tSagittarius\nHoroscope:\t\tSomeday you will travel into the multiverse."
		: (m == 12 && d >= 22) || (m == 1 && d <= 19)
		? "Your sign is:\t\tCapricorn\nHoroscope:\t\tYou will achieve inner peace."
		: ""
		);
}

int
check_date(int m, int d) {
	return !(m < 1
			|| m > 12
			|| d < 1
			|| d > 31
			|| ((m == 4
					|| m == 6
					|| m == 9
					|| m == 11)
					&& d > 30)
			|| (m == 2
					&& d > 29));
}

int main(int argc, char *argv[]) {
	time_t t = time(0);
	struct tm *today = localtime(&t);
	int todaymonth = today -> tm_mon;
	int todayday = today -> tm_mday;
	int birth_month;
	int birth_day;
get_birth:
	printf("What month were you born in? (number): ");
	scanf("%d", &birth_month);
	while(getchar() != '\n');
	printf("What day (number): ");
	scanf("%d", &birth_day);
	while(getchar() != '\n');
	if (!check_date(birth_month, birth_day)) {
		printf("Error: date does not exist.\n");
		goto get_birth;
	}
	printf("Your birthday is:\t");
	birthdate(birth_month, birth_day);
	printf("\t\t%s\n", todaymonth && birth_day == todayday ? "Happy Birthday to You!" : "");
	sign(birth_month, birth_day);
}

