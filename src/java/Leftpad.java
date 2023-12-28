import java.util.concurrent.TimeUnit;
public class Leftpad {
	public static void main(String[] args) {
		long time = System.nanoTime();
		for (int i = 0; i < 1_000_000; i++)
			Leftpad1.leftpad("hi", 10);
		time = System.nanoTime() - time;
		System.out.println(time);
		System.out.printf("%d seconds.%n", TimeUnit.NANOSECONDS.toSeconds(time));
		time = System.nanoTime();
		for (int i = 0; i < 1_000_000; i++)
			Leftpad2.leftpad("hi", 10);
		time = System.nanoTime() - time;
		System.out.println(time);
		System.out.printf("%d seconds.%n", TimeUnit.NANOSECONDS.toSeconds(time));
	}
}
