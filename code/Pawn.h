#pragma once
#include "piece.h"
class Board;
class Pawn:public Piece{
 	public:
		Pawn(const char color, Coordinate position);
	        bool makeMove(const Coordinate toPosition, Board &board);
	        std::vector<Coordinate> legalMoves(const Board &b);
		Piece *copy();
		bool isNeverMoved() const;
		bool isMoveForward(const Coordinate toPosition);
		bool isMoveTwoSteps(const Coordinate toPosition);
		bool isCapture(const Coordinate toPosition);
		bool canPromote();
	protected:
		bool neverMoved;
		
};
