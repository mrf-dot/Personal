import java.util.Scanner;

public class PizzaPlace {
	private static Scanner in = new Scanner(System.in);

	public static double BuildYourPizza(int Pizzas) {
		double total = 0;
		for (int i = 0; i < numPizzas; i++) {
			System.out.printf("Pizza #%d%n", i);
			System.out.print("What size would you like your pizza?\n"
					+ "1\tsmall\n"
					+ "2\tmedium\n"
					+ "3\tlarge\n");
			Pizza pie new Pizza (in.nextInt());
			System.out.println("Please add any toppings, or done when you are finished.");
			String toppings = in.next();
			while(!topping.equalsIgnoreCase("done")) {
				pie.addTopping(topping);
				System.out.println(pie);
				System.out.print("Please add any toppings, or 'done' when finished!");
				topping = in.next();
			}
			System.out.println("Great! Here is your final pizza:");
			System.out.println(pie);
			total += pie.getPrice();
		}
	}
}
