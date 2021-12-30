public class FizzBuzz {
	public static void main(String[] args) {
		for (int i = 1; i < 101; i++) {
			String fizz = "";
			fizz += (i % 3 == 0) ? "Fizz" : "";
			fizz += (i % 5 == 0) ? "Buzz" : "";
			System.out.println((fizz.isBlank()) ? i : fizz);
		}
	}
}
