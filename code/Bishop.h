#pragma once
#include "piece.h"
class Board;
class Bishop:public Piece{
 	public:
		Bishop(char color, int * position);
	        bool makeMove(int * toPosition,Board * b);
	        int ** legalMoves();
};
