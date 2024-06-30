public class CoolMath {
	public static void main(String[] args) {
		int a = 2, b = 3;
		System.out.println(isEven(a));
		System.out.println(isEven(b));
		System.out.println(circumference(b));
		System.out.println(pythagorean(a, b));
	}

	public static boolean isEven(int x) {
		return x % 2 == 0;
	}

	public static double circumference(double radius) {
		return 2 * Math.PI * radius;
	}

	public static double pythagorean(int a, int b) {
		return Math.sqrt(Math.pow(a, 2) + Math.pow(b, 2));
	}
}
