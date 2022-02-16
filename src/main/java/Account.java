class Account {
	private boolean accountLocked = false;
	private int balance;
	private int pin;
	private String firstName = "";
	private String lastName = "";
	private String fullName = "";

	public Account(int balance, int pin, String firstName, String lastName) {
		this.balance = balance;
		this.pin = pin;
		this.firstName = firstName;
		this.lastName = lastName;
		this.fullName = String.format("%s, %s", lastName, firstName);
		// Add values to the database below
	}

	public Account(String firstName, String lastName, int pin) throws IllegalArgumentException {
		/*
		 * Check if matching firstName with LastName exists in the database
		 * If so check if pin matches pin in database for that account
		 * Create account object from the information in the database
		 */
		this.fullName = String.format("%s, %s", lastName, firstName);
		//if (!existsInDatabase(this.fullName))
		//	throw new IllegalArgumentException("Invalid account.")
		//else if (database.fullname.accountLocked)
		//	throw new IllegalArgumentException("Account locked.")
		//if (pin == databse.fullName.pin)
			this.balance = 0; // = retrieved database object balance for first name, last name, pin combo
		} else {
			throw new IllegalArgumentException("Invalid pin.");
		}
		this.firstName = firstName;
		this.lastName = lastName;
	}

	public int getBalance() {
		return balance;
	}

	public String getName(String namePart) {
		switch (namePart) {
			case "first":
				return this.firstName;
			case "last":
				return this.lastName;
			case "full":
			default:
				return this.fullName;
		}
	}

	public void setBalance(int amountWithdrawn) {
		this.balance -= amountWithdrawn;
	}
}
