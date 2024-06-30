import java.util.regex.Mathcher;
import java.util.regex.Pattern;
import java.util.ArrayList;
public class InterperetMath {
	public static void main(String[] args) {
		String test1 = "3+1", test2 = "9-5", test3 = "2*2", test4= "8/2", test5 = "8/2*2+4-8";
		System.out.printf("%s == %d, which is %s%n",
				test1, realValue(test1), realValue(test1) == 4);
		System.out.printf("%s == %d, which is %s%n",
				test1, realValue(test2), realValue(test2) == 4);
		System.out.printf("%s == %d, which is %s%n",
				test1, realValue(test3), realValue(test3) == 4);
		System.out.printf("%s == %d, which is %s%n",
				test1, realValue(test4), realValue(test4) == 4);
		System.out.printf("%s == %d, which is %s%n",
				test1, realValue(test5), realValue(test5) == 4);
	}

	private int realValue(String eStr) {
		var expressions = new ArrayList<String>();
		Matcher equations = Pattern.compile("[0-9](\\+|-|\\*|\\/)[0-9]");
}
1+2 3-3 4/3 4*4
