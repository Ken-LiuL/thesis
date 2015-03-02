#pragma once
#include "piece.h"
#include <vector>
class Board;
class Bishop:public Piece{
 	public:
		Bishop(char color, int * position);
	        bool makeMove(const int * toPosition,Board &b);
	        std::vector<int*> legalMoves(const Board &b);
};
