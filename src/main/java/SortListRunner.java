public class SortListRunner {
	public static void main(String[] args) {
		SortList sl1 = new SortList();
		System.out.println(sl1);
		sl1.setMilliseconds(100);
		sl1.fullSort("quick");
	}
}
