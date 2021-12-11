public class PrintF {
	public static void main(String[] args) {
		double dblTotal = 1_000_000.999999;
		int intValue = -1_000_000;
		String stringVal = "This is a sentence.";
		System.out.printf("Total is: $%,.2f%n", dblTotal);
		System.out.printf("Total: %-10.2f: ", dblTotal);
		System.out.printf("% 4d", intValue);
		System.out.printf("%20.10s\n", stringVal);

		String s = "Hello World";
		System.out.printf("The string %s", s);
	}
}
