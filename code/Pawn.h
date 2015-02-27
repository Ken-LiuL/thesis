#pragma once
#include "piece.h"
class Board;
class Pawn:public Piece{
 	public:
		Pawn(char color, int * position);
	        bool makeMove(int * toPosition,Board * board);
	        int ** legalMoves();
		bool isMoveForward(int * toPosition);
		bool isMoveTwoSteps(int * toPosition);
		bool isCapture(int * toPosition);
		bool canPromote();
	protected:
		bool neverMoved;
		
};
