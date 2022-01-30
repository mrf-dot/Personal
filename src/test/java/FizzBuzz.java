public class FizzBuzz {
	public static void main(String[] args) {
		for (int i = 1; i < 101; i++) {
			String fizzS = "";
			fizzS += i % 3 == 0 ? "Fizz" : "";
			fizzS += i % 5 == 0 ? "Buzz" : "";
			System.out.println(fizzS.isBlank() ? i : fizzS);
		}
	}
}
