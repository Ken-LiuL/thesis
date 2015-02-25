#include "piece.h"
class Rook:public Piece{
 	public:
		Rook(char color, int * position);
	        void makeMove(int * toPosition);
	        bool moveIsLegal(int * toPosition);
	        int ** legalMoves();
};
