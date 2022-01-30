public class Trig {
	public static void main(String[] args) {
			System.out.println(heron(4, 3, 2));
			System.out.println(lawOfCosines(1, 2, 18.5));
	}

	public static double heron(double a, double b, double c) {
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

	public static double lawOfCosines(double a, double b, double C) {
		return Math.sqrt(Math.pow(a, 2) + Math.pow(b, 2) - 2 * a * b * Math.cos(C));
	}
}
