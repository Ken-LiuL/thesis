#pragma once
class Board;
class Piece{
	public:
		Piece(char identifier,int value,char color,int * position);
		int *getPosition();
		int getValue();
		void setPosition(int * position);
		char getColor();
		char getIdentifier();
	        virtual bool makeMove(int * toPosition,Board * board)=0;
	        virtual int ** legalMoves()=0;
	protected:
		int value;
		char color;
		int * position;
		char identifier;	
};

