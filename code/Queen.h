#pragma once
#include "piece.h"
#include <vector>
class Board;
class Queen:public Piece{
 	public:
		Queen(char color, int * position);
	        bool makeMove(const int * toPosition,Board &b);
	        std::vector<int*> legalMoves(const Board &b);
};
