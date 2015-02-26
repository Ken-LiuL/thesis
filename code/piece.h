#pragma once
class Piece{
	public:
		Piece(char identifier,int value,char color,int * position);
		int *getPosition();
		int getValue();
		void setPosition(int * position);
		char getColor();
		char getIdentifier();
	        void makeMove(int * toPosition);
	        virtual int ** legalMoves()=0;
	        virtual bool moveIsLegal(int * toPosition)=0;
	protected:
		int value;
		char color;
		int * position;
		char identifier;	
};

