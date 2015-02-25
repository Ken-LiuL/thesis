#ifndef PIECE_H
#define PIECE_h
class Piece{
	public:
		Piece(int value,char color,int * position);
		int *getPosition();
		int getValue();
		char getColor();
	        virtual void makeMove(int * toPosition)=0;
	        virtual int ** legalMoves() = 0 ;
	        virtual bool moveIsLegal(int * toPosition)=0;
	protected:
		int value;
		char color;
		int * position;
		
};
#endif

