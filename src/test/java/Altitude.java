public class Altitude {
	private int currentAltitude;
	private int maxAltitude;
	private int minAltitude;

	public Altitude(int minAltitude, int maxAltitude) {
		this.minAltitude = minAltitude;
		this.maxAltitude = maxAltitude;
	}

	public Altitude() {
		this(2_000, 50_000);
	}

	public void setAltitude(int currentAltitude) {
		if (currentAltitude < minAltitude)
			System.out.println("Altitude too low!");
		else if (currentAltitude > maxAltitude)
			System.out.println("Altitude too high!");
		else
			this.currentAltitude = currentAltitude;
	}

	public void descend() {
		setAltitude(this.currentAltitude - 1_000);
	}

	public void ascend() {
		setAltitude(this.currentAltitude + 1_000);
	}

	public int getAltitude() {
		return this.currentAltitude;
	}

	public String toString() {
		return String.format("Current Altitude: %d%n"
				+ "Min Altitude: %d%n"
				+ "Max Altitude: %d%n", this.currentAltitude, this.minAltitude, this.maxAltitude);
	}
}
