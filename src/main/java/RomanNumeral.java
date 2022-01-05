import java.util.HashMap

public class RomanNumeral {

}

class Roman {
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
	private static HashMap<String, Integer> conversionChart  = new HashMap<String, Integer>();
	private String romanNumeral;

	public Roman(String romanNumeral) {
		this.romanNumeral = romanNumeral;
	}

	private void fillConversionChart() {
		conversionChart.put("M", 1000);
		conversionChart.put("CM", 900);
		conversionChart.put("D", 500);
		conversionChart.put("CD", 400);
		conversionChart.put("C", 100);
		conversionChart.put("XC", 90);
		conversionChart.put("L", 50);
		conversionChart.put("XL", 40);
		conversionChart.put("X", 10);
		conversionChart.put("IX", 9);
		conversionChart.put("V", 5);
		conversionChart.put("IV", 4);
		conversionChart.put("I", 1);
	}

	public String getValue() {
		return romanNumeral;
	}

	private int getCharacterValue(String numeral) {
		for (
	public int toDecimal() {
		int decimalRepresentation = 0;
		for (String s = romanNumeral; !s.isEmpty(); s = s.substring(1)) {
			for (

	}

}
