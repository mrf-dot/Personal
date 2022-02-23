public class FizzBuzz {
	public static void main(String[] args) {
		for (int i = 1; i < 101; i++) {
			String s = "";
			s += i % 3 == 0 ? "Fizz" : "";
			s += i % 5 == 0 ? "Buzz" : "";
			System.out.println(s.isBlank() ? i : s);
		}
	}
}
