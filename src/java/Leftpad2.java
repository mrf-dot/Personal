public class Leftpad2 {
	public static String leftpad(String str, int len) {
		return leftpad(str, len, ' ');
	}

	public static String leftpad(String str, int len, char ch) {
		for (int i = 0; i < len; i++)
			str = ch + str;
		return str;
	}
}
