public class vowel_replace {
	public static String vowelShift(String vowelString) {
		String vowels = "aeiou";
		String transformed = vowelString;
		for (String vowel:vowels){
			transformed = transformed.replace(vowel, '*');
		}
		return transformed;
	}
	public static void main(String[] args) {
		String sample = "This string contains vowels";
		System.out.print(vowelShift(sample));

	}

}
