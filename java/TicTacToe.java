public class TicTacToe {
	public static void main(String[] args) {

	}
}

class Board {
	private String[][] positions;
	private char playerSymbol;
	private char aiSymbol;
	public Board(boolean startFirst, int size) {
		this.positions = fill(size);
		this.playerSymbol = startFirst ? 'X' : 'O';
		this.aiSymbol = startFirst ? 'O' : 'X';
	}

	public Board() {
		this(true, 3);
	}


	// Displays board
	// adds position to board
	// checks for winner
	// creates an empty board
	private String[][] fill(int size){

	};
}
