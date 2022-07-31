/* A model of a sample banking system written in C */
struct
account {
	unsigned long id;
	/* Amount of money in the account in pennies */
	long balance;
	char[30] firstname;
	char[30] lastname;
	/* pin will be hashed in account struct */
	char[100] pin;
	/*
	 * 0 indicates pin has not yet been entered correctly,
	 * 1 indicates account has been verified
	 */
	int unlocked;
}

/* Hashes and salts a plaintext pin number */
char *
hash(pin);

/* Make a deposit */
int
deposit(account *a, int amt);

/* Withdraw from savings */
int
withdraw(account *a, int amt);

/* Write the changes made to the account to the database */
int
waccount(account *a);

/* Create an account */
int
maccount(account *a);

/* Delete an account */
int
daccount(account *a);

/* Verify pin number for account is correct and unlock the account */
int
unlock(account *a, int pin);

