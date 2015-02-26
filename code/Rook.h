#include "piece.h"
class Rook:public Piece{
 	public:
		Rook(char color, int * position);
	        bool moveIsLegal(int * toPosition);
	        int ** legalMoves();
};
