#include "piece.h"
class Bishop:public Piece{
 	public:
		Bishop(char color, int * position);
	        bool moveIsLegal(int * toPosition);
	        int ** legalMoves();
};
