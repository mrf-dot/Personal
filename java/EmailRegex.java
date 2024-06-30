import java.util.Scanner;
import java.util.regex.Pattern;
import java.util.regex.Matcher;

public class EmailRegex {
	public static void main(String[] args) {
		Pattern emailPattern = Pattern.compile("\\S+@\\S+\\.[a-z]+");
		Matcher emailMatch;
		Scanner scanChar = new Scanner(System.in);
		do {
			System.out.print("Enter a valid email: ");
			emailMatch = emailPattern.matcher(scanChar.nextLine());
			if (emailMatch.matches())
				System.out.println("It's a match!");
			else
				System.out.println("Try again.");

		} while (!emailMatch.matches());
		scanChar.close();
	}
}
