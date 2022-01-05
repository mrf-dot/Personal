interface groove {
	public void animalSound();

	public void sleep();
}

class Pig implements groove {
	public void animalSound() {
		System.out.println("x");
	}

	public void sleep() {
		System.out.println("y");
	}
}

class Main {
	public static void main(String[] args) {
		Pig myPig = new Pig();
		myPig.animalSound();
		myPig.sleep();
	}
}
