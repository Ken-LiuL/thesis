#include "piece.h"
class Bishop:public Piece{
 	public:
		Bishop(char color, int * position);
	        void makeMove(int * toPosition);
	        bool moveIsLegal(int * toPosition);
	        int ** legalMoves();
};
