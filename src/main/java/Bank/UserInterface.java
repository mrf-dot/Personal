import java.util.Scanner;

public class UserInterface {
	private static Scanner scanNum = new Scanner(System.in);
	private static Scanner scanStr = new Scanner(System.in);
	public static void main(String[] args) {
		System.out.print("1\tCreate Account\n"
				+ "2\tCheck Account Balance\n"
				+ "3\tWithdraw Funds"
				+ "4\tAdd Funds\n");
		int option;
		do {
			System.out.print("Select an option: ");
			option = scanNum.nextInt();
		} while (option < 1 || option > 4);
		switch (option) {
			case 1:
				createAccount();
				break;
			case 2:
				System.out.printf("Your account balance is:\t$%.2f%n", (float) login().getBalance() / 100);
				break;
			case 3:
				withdrawFunds(login());
				break;
			case 4:
				addFunds(login());
				break;
			default:
				System.err.println("Invalid option selected");
				break;
		}
	}

	public static void createAccount() {
		new Account(balance, pin, firstName, lastName);
	}

	public static Account login() {
		return new Account(firstName, lastName, pin);
	}
}
