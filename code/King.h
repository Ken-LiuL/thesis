#pragma once
#include "piece.h"
#include <vector>
class Board;
class King:public Piece{
 	public:
		King(const char color, Coordinate position);
	        bool makeMove(const Coordinate toPosition,Board &b);
		Piece *copy();
	        std::vector<Coordinate> legalMoves(const Board &b);
		std::vector<Coordinate> legalMovesWithoutCastling(const Board &b);
	protected:
		bool neverMoved;
};
