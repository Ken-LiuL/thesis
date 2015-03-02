#pragma once
#include "piece.h"
#include <vector>
class Board;
class Knight:public Piece{
 	public:
		Knight(char color, int * position);
	        bool makeMove(const int * toPosition,Board &b);
	        std::vector<int*> legalMoves(const Board &b);
	private:
		bool reachablePosition(const int * p,const Board &b);
};
