#pragma once
#include "piece.h"
class Board;
class Knight:public Piece{
 	public:
		Knight(char color, int * position);
	        bool makeMove(int * toPosition,Board * b);
	        int ** legalMoves();
};
