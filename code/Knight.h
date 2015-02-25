#include "piece.h"
class Knight:public Piece{
 	public:
		Knight(char color, int * position);
	        void makeMove(int * toPosition);
	        bool moveIsLegal(int * toPosition);
	        int ** legalMoves();
};
