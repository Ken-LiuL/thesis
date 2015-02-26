#include "piece.h"
class Pawn:public Piece{
 	public:
		Pawn(char color, int * position);
	        bool moveIsLegal(int * toPosition);
	        int ** legalMoves();
};
