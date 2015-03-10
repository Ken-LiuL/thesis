#pragma once
#include "piece.h"
#include <vector>
class Board;
class Queen:public Piece{
 	public:
		Queen(const char color, Coordinate position);
	        bool makeMove(const Coordinate toPosition,Board &b);
		Piece *copy();
	        std::vector<Coordinate> legalMoves(const Board &b);
};
