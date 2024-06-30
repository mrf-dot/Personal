public class Leftpad1 {
	public static String leftpad(String str, int len) {
		return leftpad(str, len, ' ');
	}

	public static String leftpad(String str, int len, char ch) {
		StringBuilder sb = new StringBuilder(str);
		for (int i = 0; i < len; i++)
			sb.insert(0, ch);
		return sb.toString();
	}
}
