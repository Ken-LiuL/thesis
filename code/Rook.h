#pragma once
#include "piece.h"
#include <vector>
class Board;
class Rook:public Piece{
 	public:
		Rook(const char color, Coordinate position);
	        bool makeMove(const Coordinate toPosition,Board &b);
		Piece *copy();
	        std::vector<Coordinate> legalMoves(const Board &b);
		bool isNeverMoved();
	protected:	
		bool neverMoved;
};
