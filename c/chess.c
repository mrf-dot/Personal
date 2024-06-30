/*
 * The source code for a simple chess engine in C
 * This program drew inspiration from the book "Toledo Nanochess: the commented source code"
 *
 * Requirements:
 * A way to represent the chessboard
 * Codes for chessmen
 * Preservation of information about movement of king and rooks (needed for castling)
 * Preservation of information about the last pawn moved two squares ahead (needed for en passant)
 * Indication of actual playing side (white or black)
 * Information for discovering repeated postiions and the rule of 50 movements (optional): A player can claim a draw if no capture has been made and no pawns have been moved in the last 50 moves
 *
 * indexes can be converted to one dimension: eg b3 (2,3) can be found in one dimension with 2 * board-width (8) * 3
 *
 */
#define WHITE 0
#define BLACK 1

#define EMPTY 0
#define PAWN 1
#define KNIGHT 2
#define BISHOP 3
#define ROOK 4
#define QUEEN 5
#define KING 6

#define HEIGHT 0x10
#define WIDTH 0x10


struct Piece {
	unsigned int color: 1;
	unsigned int value: 3;
	unsigned int moved: 1;
};
struct Piece chessboard[0x100];

void
move_knight(int square) {
	int target = square - 0x21;
	if (!(target & 0x88) && chessboard[target]

