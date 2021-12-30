import java.util.Scanner;

/**
 * Provides utilities for a cli number game in java.
 * The program first generates a random number within a user defined
 * range. The user is then prompted to enter a number until they guess
 * the randomly generated number. The user will have 100 tries to guess
 * the number, then the program will display a "game over" message. if
 * If the user guesses correctly they will see a message displayed showing
 * whether they guessed correct, the number of guesses they made, their
 * average amount of guesses per round, and their win/loss ratio. The user
 * will then be prompted to guess again
 */
public class NumberGame {
	public static Scanner scanStr = new Scanner(System.in), scanNum = new Scanner(System.in);

	/**
	 * Creates the cli for the program.
	 *
	 * @param args added for semantics
	 */
	public static void main(String[] args) {
		System.out.print("This is a number guessing game.\n"
				+ "1\t1-100\n"
				+ "2\t1-1,000\n"
				+ "3\t1-10,000 (Default)\n"
				+ "4\t1-100,000\n"
				+ "5\t1-1,000,000\n"
				+ "Select a range: ");
		int difficulty = getDifficulty();
		int rounds = 0;
		int wins = 0;
		int totalGuesses = 0;
		while (true) {
			int roundGuesses = guessingRound(getRandom(difficulty));
			if (roundGuesses != 100) {
				wins++;
				System.out.println("Congratulations! You won.");
			} else {
				System.out.println("You lost.");
			}
			totalGuesses += roundGuesses;
			rounds++;
			System.out.printf("%nYour game stats are:%n"
					+ "Round Guesses:\t\t%d%n"
					+ "Total Guesses:\t\t%d%n"
					+ "Average Guesses:\t%d%n"
					+ "Rounds played:\t\t%d%n"
					+ "Win ratio:\t\t%.2f%%%n%n",
					roundGuesses, totalGuesses, totalGuesses / rounds, rounds, ((double) wins / rounds) * 100);
			playAgain();
		}
	}

	/**
	 * This method executes a round of the guessing game. The client is given
	 * 100 tries to guess the a randomly chosen number. The function will
	 * return the number of attempts the user took to guess the number. If the
	 * client takes more than 100 tries the method will return 100.
	 *
	 * @param correct An number the client will attempt to guess the identity of
	 * @return the number of attempts the client took to guess the number
	 */
	public static int guessingRound(int correct) {
		for (int i = 1; i < 101; i++) {
			System.out.print("Try to guess my number: ");
			if (checkNum(scanNum.nextInt(), correct))
				return i;
		}
		return 100;
	}

	public static int getDifficulty() {
		int difficulty = 3;
		if (scanNum.hasNextInt())
			difficulty = scanNum.nextInt();
		return (difficulty < 1 || difficulty > 5) ? 3 : difficulty;
	}

	/**
	 * Generates a random number using Math.random and multiplies it by
	 * either 100, 1,000, 10,000, 100,000, or 1,000,000 based on the
	 * number supplied as an argument in a range of 1 - 5. If the
	 * number is out of the range of 1-5 then the method will generate
	 * a random number between 0 and 10,000.
	 *
	 * @param difficulty a number 1-5 indicating the range of the random number
	 * @return a number in a range based on a number 1-5 from 100 to 1,000,000
	 */
	public static int getRandom(int difficulty) {
		return (int) (Math.random() * Math.pow(10, difficulty + 1)) + 1;
	}

	/**
	 * Checks two numbers against each other and returns either true
	 * or false based on whether they are equal or not. A message is
	 * also sent to standard output indicating whether the first number
	 * is greater or less than the second number.
	 *
	 * @param guessedNum the number to compare
	 * @param realNum    the number used to check the user inputted number
	 * @return true if guessedNum is equal to realNum
	 */
	public static boolean checkNum(int guessedNum, int realNum) {
		if (guessedNum == realNum)
			return true;
		if (guessedNum > realNum)
			System.out.println("Your guess is too high.");
		if (guessedNum < realNum)
			System.out.println("Your guess is too low.");
		return false;
	}

	/**
	 * Prompts the client to enter whether they wish to play again.
	 */
	public static void playAgain() {
		while (true) {
			System.out.print("Would you like to play again? (y/n): ");
			String userChoice = scanStr.nextLine().toLowerCase();
			if (userChoice.equals("y"))
				return;
			else if (userChoice.equals("n"))
				System.exit(0);
			else
				System.out.println("Please enter either 'y' or 'n'.");
		}
	}
}
