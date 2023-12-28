public class Factorial {
	public static void main(String[] args) {
		for (long i = 1l; i < 1000l; i++) {
			System.out.printf("%d:\t", i);
			System.out.println(Long.toString(factorial(i)));
		}
	}

	public static long factorial(long n) {
		long result = 1l;
		for (long i = 2l; i <= n; i++)
			result *= i;
		return result;
	}

}
