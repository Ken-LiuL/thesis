#include "piece.h"
class King:public Piece{
 	public:
		King( char color, int * position);
	        bool moveIsLegal(int * toPosition);
	        int ** legalMoves();
};
