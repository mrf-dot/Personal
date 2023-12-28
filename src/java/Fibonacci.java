import java.util.ArrayList;
import java.math.BigInteger;

public class Fibonacci {
	static final BigDecimal SQRT_5 = BigDecimal.valueOf(Math.sqrt(5));
	static final BigDecimal GR = (BigDecimal.ONE.add(SQRT_5).divide(BigDecimal.valueOf(2));
	static final BigDecimal NGR = GR.negate().add(BigDecimal.ONE);

// Binet algorithm
private static long fibGoldenRatio(int n) {

  if (n < 0) {
     return -1;
  }

  return BigDecimal.ONE.divide(SQRT_5).multiply((GR.pow(n).substract(NGR.pow(n)))).toBigInteger().longValue();
}
	private static ArrayList<BigInteger> fibSequence = new ArrayList<BigInteger>();

	public static void main(String[] args) {
		// System.out.printf("The 100th Fibonacci number is %,d%n", getNumber(100));
		// System.out.printf("The 101th Fibonacci number is %,d%n", getNumber(101));
		// showSequence(100_000);
		System.out.printf("The millionth Fibonacci number is %,d%n", getNumber(1_000_000));
		System.out.printf("The million and first Fibonacci number is %,d%n", getNumber(1_000_001));
	}

	public static void showSequence(int index) {
		fillSequence(index);
		for (int i = 1; i < index + 1; i++)
			System.out.printf("%,d.\t%d%n%n", i, fibSequence.get(i));
	}

	public static BigInteger getNumber(int n) {
		double phi = 1.61803;
		return Math.floorDiv((long) Math.pow(phi, n) - (long) Math.pow(-phi, -n), Math.sqrt(5));
	}

	public static void fillSequence(int index) {
		if (fibSequence.size() == 0) {
			fibSequence.add(BigInteger.valueOf(0));
			fibSequence.add(BigInteger.valueOf(1));
		}
		for (int i = fibSequence.size(); i < index + 1; i++)
			fibSequence.add(
					fibSequence.get(i - 1).add(fibSequence.get(i - 2)));
	}
}
