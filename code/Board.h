#pragma once
#include <vector>
class Piece;
class Board{
	public:
		struct EnPassant{
			Piece * p;
			int step;
		};  
	
		Board(int n,std::vector<Piece *>  p);
		void initialize();
		void display();
		void doPromotion(Piece * p);
		bool occupied(const int * position) const;
		void increaseSteps();
		void capture(int * from, int * to);
		Piece * getPiece(const int * toPosition) const;
		EnPassant * getPassant() const;
		int currentStep() const;
		void setPassant(Piece * p);
		bool makeMove(int * from,int * to);
	

	protected:
		std::vector<Piece *>   pieces;// list of pointers of pieces
		int numberOfPieces;// number of pieces in the board
		Piece * board[8][8];// 8*8 board that contains pointers that points to pieces in the list, used to display in graph
		int steps;// record how many steps have been  since the beginning of a game
		EnPassant * passant;// record the pawn just step forward two squares, so that en passant is possible
		
};

