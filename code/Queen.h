#include "piece.h"
class Queen:public Piece{
 	public:
		Queen(char color, int * position);
	        void makeMove(int * toPosition);
	        bool moveIsLegal(int * toPosition);
	        int ** legalMoves();
};
