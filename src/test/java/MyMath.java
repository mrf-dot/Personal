public class MyMath {
        private int n1;
        private int n2;

        public void main() {
                System.out.printf("n1 = %d%n"
                                + "n2 = %d%n"
                                + "n1 + n2 = %d%n"
                                + "n1 - n2 = %d%n"
                                + "n1 x n2 = %d%n"
                                + "n1 / n2 = %d%n"
                                + "n1 ^ n2 = %.2f%n",
                                n1,
                                n2,
                                add(),
                                subtract(),
                                multiply(),
                                divide(),
                                pow()
                                );
        }

        public MyMath() {
                this(1, 2);
        }

        public MyMath(int n1, int n2) {
                this.n1 = n1;
                this.n2 = n2;
        }

        public int add() {
                return n1 + n2;
        }

        public int subtract() {
                return n1 - n2;
        }

        public int multiply() {
                return n1 * n2;
        }

        public int divide() {
                return n1 / n2;
        }

        public double pow() {
                return Math.pow(n1, n2);
        }

        public String toString() {
                return String.format("n1: %d | n2: %d", n1, n2);
        }

        public int getN1() {
                return n1;
        }

        public int getN2() {
                return n2;
        }

        public void setN1(int n1) {
                this.n1 = n1;
        }

        public void setN2(int n2) {
                this.n2 = n2;
        }
}
