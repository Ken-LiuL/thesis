#pragma once
#include <vector>
class Board;
class Piece{
	public:
		Piece(char identifier,int value,char color,int * position);
		~Piece();
		int *getPosition() const;
		int getValue() const;
		void setPosition(const int * position);
		virtual Piece *copy()=0;
		char getColor() const;
		char getIdentifier() const;
	        virtual bool makeMove(const int * toPosition, Board  &board)=0;
	        virtual std::vector<int*> legalMoves(const Board &b)=0;
	protected:
		int value;
		char color;
		int * position;
		char identifier;	
};

