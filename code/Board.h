#pragma once
class Piece;
class Board{
	public:
		struct EnPassant{
			Piece * p;
			int step;
		};  
	
		Board(int n,Piece ** p);
		void initialize();
		void display();
		void doPromotion(Piece * p);
		bool occupied(int * position);
		void increaseSteps();
		void capture(int * from, int * to);
		Piece * getPiece(int * toPosition);
		EnPassant * getPassant();
		int currentStep();
		void setPassant(Piece * p);
		bool makeMove(int * from,int * to);
	

	protected:
		Piece ** pieces;// list of pointers of pieces
		int numberOfPieces;// number of pieces in the board
		Piece * board[8][8];// 8*8 board that contains pointers that points to pieces in the list, used to display in graph
		int steps;// record how many steps have been  since the beginning of a game
		EnPassant * passant;// record the pawn just step forward two squares, so that en passant is possible
		
};

