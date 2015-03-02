#pragma once
#include "piece.h"
#include <vector>
class Board;
class King:public Piece{
 	public:
		King( char color, int * position);
	        bool makeMove(const int * toPosition,Board &b);
	        std::vector<int*> legalMoves(const Board &b);
};
