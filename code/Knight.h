#include "piece.h"
class Knight:public Piece{
 	public:
		Knight(char color, int * position);
	        bool moveIsLegal(int * toPosition);
	        int ** legalMoves();
};
