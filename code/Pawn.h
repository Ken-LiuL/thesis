#pragma once
#include "piece.h"
class Board;
class Pawn:public Piece{
 	public:
		Pawn(char color, int * position);
	        bool makeMove(const int * toPosition, Board &board);
	        std::vector<int*> legalMoves(const Board &b);
		Piece *copy();
		bool isNeverMoved() const;
		bool isMoveForward(const int * toPosition);
		bool isMoveTwoSteps(const int * toPosition);
		bool isCapture(const int * toPosition);
		bool canPromote();
	protected:
		bool neverMoved;
		
};
