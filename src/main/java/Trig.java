public class Trig {
	public static void main(String[] args) {
		System.out.printf("The area of your triangle is: %.3f",
				getArea(4, 3, 2));
	}

	public static double getArea(double a, double b, double c) {
		if (a <= 0
				|| b <= 0
				|| c <= 0
				|| a + b < c
				|| b + c < a
				|| a + c < b)
			return -1d;

		double s = (a + b + c) / 2;
		return Math.sqrt(s * (s - a) * (s - b) * (s - c));
	}
}
