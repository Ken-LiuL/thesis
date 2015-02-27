#pragma once
#include "piece.h"
class Board;
class King:public Piece{
 	public:
		King( char color, int * position);
	        bool makeMove(int * toPosition,Board * b);
	        int ** legalMoves();
};
