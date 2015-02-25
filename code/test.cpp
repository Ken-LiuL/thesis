#include "piece.h"

class Test:public Piece{
	public:
		Test(char color,int * position):Piece::Piece(500,color,position){}
	        void makeMove(int * position){}
	        bool moveIsLegal(int * position){ return 1;}
		int ** legalMoves(){}

};

int main(){

	int * p = new int[2];
	p[0] = 1;
	p[1] = 2;
	Piece t = Test('W',p);

}
