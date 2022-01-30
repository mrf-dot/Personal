public class FizzBuzz {
	public static void main(String[] args) {
		String fizzString = "";
		for (int i = 1; i < 101; i++) {
			fizzString = "";
			fizzString += (i % 3 == 0) ? "Fizz": "";
			fizzString += (i % 5 == 0) ? "Buzz": "";
			System.out.println((fizzString.isBlank()) ? i : fizzString);
		}
	}

	public static void superfluous() {
		return;
	}
}
