import java.util.Scanner;

public class FeigenbaumU3 {
	// Defines alphabet
	private static String alphabetLower = "abcdefghijklmnopqrstuvwxyz";
	private static String alphabetUpper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	public static void main(String[] args) {
		Scanner scanChar = new Scanner(System.in);
		Scanner scanNum = new Scanner(System.in);
		System.out.println("Program input: A string, a shift, encrypt/decrypt option");
		System.out.println("Program output: Either a decrypted or encrypted string based on user input");
		System.out.print("Enter a string: ");
		String message = scanChar.nextLine();
		System.out.print("Enter a shift: ");
		int key;
		do {
			key = scanNum.nextInt() % 26;
			if (key == 0)
				System.out.print("Please enter a number which is not a multiple of 26: ");
		} while (key == 0);
		String mode = "";
		do {
			System.out.print("Type 'e' to encrypt the string or 'd' to decrypt the string: ");
			mode = scanChar.nextLine().toLowerCase();
			if (mode.equals("e"))
				System.out.printf("Your encrypted string is: %s%n", encrypt(message, key));
			else if (mode.equals("d"))
				System.out.printf("Your decrypted string is: %s%n", decrypt(message, key));
			else
				System.out.print("Please enter your choice again: ");
		} while (!mode.equals("e") && !mode.equals("d"));
	}

	public static String encrypt(String message, int key) {
		String encryptedString = "";
		char currentChar;
		for (int i = 0; i < message.length(); i++) {
			currentChar = message.charAt(i);
			if (alphabetLower.indexOf(currentChar) != -1)
				encryptedString += alphabetLower
						.charAt((alphabetLower.indexOf(currentChar) + key) % 26);
			else if (alphabetUpper.indexOf(currentChar) != -1)
				encryptedString += alphabetUpper
						.charAt((alphabetUpper.indexOf(currentChar) + key) % 26);
			else
				encryptedString += currentChar;
		}
		return encryptedString;
	}

	public static String decrypt(String message, int key) {
		return encrypt(message, 26 - key);
	}
}
