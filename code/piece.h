#pragma once
#include <vector>
#include "Coordinate.h"
class Board;
class Piece{
	public:
		Piece(const char identifier,const int value,const char color,Coordinate position);
		Coordinate getPosition() const;
		int getValue() const;
		void setPosition(const Coordinate position);
		virtual Piece *copy()=0;
		char getColor() const;
		char getIdentifier() const;
	        virtual bool makeMove(const Coordinate toPosition, Board  &board)=0;
	        virtual std::vector<Coordinate> legalMoves(const Board &b)=0;
	protected:
		int value;
		char color;
		Coordinate position;
		char identifier;	
};

