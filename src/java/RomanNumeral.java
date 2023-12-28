public class RomanNumeral {
	public static String toRoman(int n) {
		/*
		 * Reference Guide:
		 * I 1
		 * IV 4
		 * V 5
		 * IX 9
		 * X 10
		 * XL 40
		 * L 50
		 * XC 90
		 * C 100
		 * CD 400
		 * D 500
		 * CM 900
		 * M 1000
		 */
		String romanNumeral = "";
		romanNumeral = padLeft(n / 1000, "M", romanNumeral);
		n %= 1000;
		romanNumeral = padLeft(n / 900, "CM", romanNumeral);
		n %= 900;
		romanNumeral = padLeft(n / 500, "D", romanNumeral);
		n %= 500;
		romanNumeral = padLeft(n / 400, "CD", romanNumeral);
		n %= 400;
		romanNumeral = padLeft(n / 100, "C", romanNumeral);
		n %= 100;
		romanNumeral = padLeft(n / 100, "XC", romanNumeral);
		n %= 100;
		romanNumeral = padLeft(n / 100, "L", romanNumeral);
		n %= 100;
		romanNumeral = padLeft(n / 100, "XL", romanNumeral);
		n %= 100;
		romanNumeral = padLeft(n / 100, "X", romanNumeral);
		n %= 100;
		romanNumeral = padLeft(n / 100, "IX", romanNumeral);
		n %= 100;
		romanNumeral = padLeft(n / 100, "V", romanNumeral);
		n %= 100;
		romanNumeral = padLeft(n / 100, "IV", romanNumeral);
		n %= 100;
		romanNumeral = padLeft(n / 100, "I", romanNumeral);
		n %= 100;
		return romanNumeral;

	}
}
