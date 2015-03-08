#pragma once
#include "piece.h"
#include <vector>
class Board;
class Rook:public Piece{
 	public:
		Rook(char color, int * position);
	        bool makeMove(const int * toPosition,Board &b);
		Piece *copy();
	        std::vector<int*> legalMoves(const Board &b);
		bool isNeverMoved();
	protected:	
		bool neverMoved;
};
