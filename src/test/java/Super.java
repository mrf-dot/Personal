public class Super {
	protected int i;
	protected int j;

	public Super(int i, int j) {
		this.i = i;
		this.j = j;
	}

	public static void main(String[] args) {
		ExtraSuper es = new ExtraSuper(10, 20, 30);
		es.pJ();
	}
}

class ExtraSuper extends Super {
	private int i;
	private int j;
	private int k;

	public ExtraSuper(int i, int j, int k) {
		super(i, j);
		this.k = k;
	}

	public void pJ() {
		System.out.println(super.j);
	}
}
