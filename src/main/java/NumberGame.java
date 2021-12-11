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
	/**
	 * Creates the cli for the program.
	 *
	 * @param args added for semantics
	 */
	public static void main(String[] args) {
		Scanner scanNum = new Scanner(System.in);
		Scanner scanStr = new Scanner(System.in);
		System.out.println("This program is a number guessing game based on a user-defined random range.");
		System.out.print("1\t1-100\n"
				+ "2\t1-1,000\n"
				+ "3\t1-10,000\n"
				+ "4\t1-100,000\n"
				+ "5\t1-1,000,000\n");
		int randomRange;
		do {
			System.out.print("Select a range: ");
			randomRange = scanNum.nextInt();
		} while (randomRange < 1 || randomRange > 5);
		int randomNumber;
		int rounds = 0;
		int wins = 0;
		int totalGuesses = 0;
		int roundGuesses;
		int currentGuess;
		String playAgain = "";
		boolean correctGuess = false;
		do {
			randomNumber = getRandom(randomRange);
			roundGuesses = 0;
			do {
				System.out.print("Try to guess my number: ");
				currentGuess = scanNum.nextInt();
				correctGuess = checkNum(currentGuess, randomNumber);
				roundGuesses++;
			} while (roundGuesses < 101 & !correctGuess);
			totalGuesses += roundGuesses;
			rounds++;
			if (correctGuess) {
				wins++;
				System.out.println("Congratulations! You won.");
			} else {
				System.out.println("You lost.");
			}
			System.out.printf("%nYour game stats are:%n"
					+ "Round Guesses:\t\t%d%n"
					+ "Total Guesses:\t\t%d%n"
					+ "Average Guesses:\t%d%n"
					+ "Rounds played:\t\t%d%n"
					+ "Win ratio:\t\t%.2f%%%n%n",
					roundGuesses, totalGuesses, totalGuesses / rounds, rounds, ((double) wins / rounds) * 100);
			do {
				System.out.print("Would you like to play again? (y/n): ");
				playAgain = scanStr.nextLine().toLowerCase();
			} while (!playAgain.equals("y") && !playAgain.equals("n"));
		} while (playAgain.equals("y"));
		scanStr.close();
		scanNum.close();
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
		switch (difficulty) {
			case 1:
				return (int) (Math.random() * 100) + 1;
			case 2:
				return (int) (Math.random() * 1_000) + 1;
			case 3:
				return (int) (Math.random() * 10_000) + 1;
			case 4:
				return (int) (Math.random() * 100_000) + 1;
			case 5:
				return (int) (Math.random() * 1_000_000) + 1;
			default:
				return (int) (Math.random() * 10_000) + 1;
		}
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
		if (guessedNum > realNum) {
			System.out.println("Your guess is too high.");
			return false;
		} else if (guessedNum < realNum) {
			System.out.println("Your guess is too low.");
			return false;
		} else {
			return true;
		}
	}
}
