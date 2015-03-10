#pragma once
#include "piece.h"
#include <vector>
class Board;
class Bishop:public Piece{
 	public:
		Bishop(const char color, Coordinate position);
	        bool makeMove(const Coordinate toPosition,Board &b);
		Piece *copy();
	        std::vector<Coordinate> legalMoves(const Board &b);
};
