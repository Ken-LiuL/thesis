#include "piece.h"
class Queen:public Piece{
 	public:
		Queen(char color, int * position);
	        bool moveIsLegal(int * toPosition);
	        int ** legalMoves();
};
