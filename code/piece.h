#pragma once
#include <vector>
class Board;
class Piece{
	public:
		Piece(char identifier,int value,char color,int * position);
		~Piece();
		int *getPosition();
		int getValue();
		void setPosition(const int * position);
		char getColor();
		char getIdentifier();
	        virtual bool makeMove(const int * toPosition, Board  &board)=0;
	        virtual std::vector<int*> legalMoves(const Board &b)=0;
	protected:
		int value;
		char color;
		int * position;
		char identifier;	
};

