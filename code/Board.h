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
		Board(Board &b);
		~Board();
		void record(int *from,int*to);
		void initialize();
		void freshBoard();
		void display();
		void doPromotion(Piece * p);
		bool occupied(const int * position) const;
		void increaseSteps();
		void capture(int * from, int * to);
		bool isUnderAttack(int * cord,char color) const;
	        std::vector<Piece*> &getPieces();
		Piece * getPiece(const int * toPosition) const;
		EnPassant * getPassant() const;
		int currentStep() const;
		void setPassant(Piece * p);
		bool makeMove(int * from,int * to);
	

	protected:
		std::vector<Piece *>   pieces;// list of pointers of pieces
		Piece * board[8][8];// 8*8 board that contains pointers that points to pieces in the list, used to display in graph
		int steps;// record how many steps have been  since the beginning of a game
		EnPassant * passant;// record the pawn just step forward two squares, so that en passant is possible
		
};

