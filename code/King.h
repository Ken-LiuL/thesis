#pragma once
#include "piece.h"
#include <vector>
class Board;
class King:public Piece{
 	public:
		King( char color, int * position);
	        bool makeMove(const int * toPosition,Board &b);
		Piece *copy();
	        std::vector<int*> legalMoves(const Board &b);
		std::vector<int*> legalMovesWithoutCastling(const Board &b);
	protected:
		bool neverMoved;
};
