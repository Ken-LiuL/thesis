#include "piece.h"
class King:public Piece{
 	public:
		King( char color, int * position);
	        void makeMove(int * toPosition);
	        bool moveIsLegal(int * toPosition);
	        int ** legalMoves();
};
