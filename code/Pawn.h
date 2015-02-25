#include "piece.h"
class Pawn:public Piece{
 	public:
		Pawn(char color, int * position);
	        void makeMove(int * toPosition);
	        bool moveIsLegal(int * toPosition);
	        int ** legalMoves();
};
