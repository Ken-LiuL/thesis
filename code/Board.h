#include "Bishop.h"
#include "Knight.h"
#include "King.h"
#include "Pawn.h"
#include "Queen.h"
#include "Rook.h"

class Board{
	public:
		Board(int n,Piece ** p);
		void initialize();
		void display();

	protected:
		Piece ** pieces;// list of pointers of pieces
		int numberOfPieces;// number of pieces in the board
		Piece * board[8][8];// 8*8 board that contains pointers that points to pieces in the list, used to display in graph
};

