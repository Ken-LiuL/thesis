#pragma once
#include <vector>
#include "Coordinate.h"
class Piece;
class Board{
	public:
		struct EnPassant{
			Piece * p;
			int step;
		};  
	
		Board(const int n,std::vector<Piece *>  p);
		Board(Board &b);
		Board();
		~Board();
		Board &operator=(Board &board);
		void initialize();
		void freshBoard();
		void display();
		void doPromotion(Piece * p);
		bool amICheckmated(char color);
		bool occupied(const Coordinate position) const;
		void increaseSteps();
		void capture(const Coordinate from, const  Coordinate to);
		bool isUnderAttack(const Coordinate cord, const char color) const;
		std::vector<Board*> nextBoardStates(char color);
	        std::vector<Piece*> &getPieces() ;
		Piece * getPiece(const Coordinate toPosition) const ;
		EnPassant * getPassant() const;
		int currentStep() const;
		void setPassant(Piece * p);
		bool makeMove(const Coordinate from,const Coordinate to);
	

	protected:
		std::vector<Piece *>   pieces;// list of pointers of pieces
		Piece * board[8][8];// 8*8 board that contains pointers that points to pieces in the list, used to display in graph
		int steps;// record how many steps have been  since the beginning of a game
		EnPassant * passant;// record the pawn just step forward two squares, so that en passant is possible
		
};

