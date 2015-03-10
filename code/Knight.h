#pragma once
#include "piece.h"
#include <vector>
class Board;
class Knight:public Piece{
 	public:
		Knight(const char color, Coordinate position);
	        bool makeMove(const Coordinate toPosition,Board &b);
	        std::vector<Coordinate> legalMoves(const Board &b);
		Piece *copy();
	private:
		bool reachablePosition(const Coordinate p,const Board &b);
};
