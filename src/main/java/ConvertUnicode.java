import java.io.File;
import java.util.Scanner;
import java.io.FileNotFoundException;

public class ConvertUnicode {
	public static void main(String[] args) {
		Scanner sFileName = new Scanner(System.in);
		File f;
		do {
			System.out.print("Enter a filename: ");
			f = new File(sFileName.nextLine());
		} while (!f.isFile());
		System.out.printf("The file you selected is %s", f);
		sFileName.close();
		convertFile(f);
	}
	public static void convertFile(File f) {
		try {

			Scanner sFile = new Scanner(f);
			String fileContents = sFile.nextLine();
			while (sFile.hasNextLine()) {
				fileContents += "\n" + sFile.nextLine();
			}
			sFile.close();
			char[] contentArray = fileContents.toCharArray();
			System.out.println(contentArray);
		} catch (FileNotFoundException fnfe) {
			fnfe.printStackTrace();
		}
	}
}
