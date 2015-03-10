#include "Rook.h"
#include "Board.h"
#include <iostream>
#include "Constants.h"
using namespace std;

Rook::Rook(const char c,Coordinate p)
	:Piece::Piece('R',500,c,p)	
	{
	neverMoved = TRUE;
}

Piece *Rook::copy(){
	return new Rook(this->color,position);
}

bool Rook::isNeverMoved(){
	return neverMoved;
}
bool Rook::makeMove(const Coordinate  toPosition, Board &b){
	/*check whether toPosition is in legalMoves, and free memory in moveVector*/
	vector<Coordinate>  moveVector = this->legalMoves(b);
	bool isLegal =  FALSE;
	for(vector<Coordinate>::iterator it=moveVector.begin();it<moveVector.end();it++){
		if((*it)==toPosition){
			isLegal = TRUE;
			this->setPosition(toPosition);
			neverMoved = FALSE;
			break;
		}
	}
	return isLegal;

}

vector<Coordinate> Rook::legalMoves(const Board &b){
	vector<Coordinate> moves(0);
	int i,j;
	//horizontal-->right
	for(i=position[1];i<7;i++){
		Coordinate p(position[0],i+1);
		if(!b.occupied(p)){
			moves.push_back(p);
		}
		else if(b.getPiece(p)->getColor() != this->getColor()){
			moves.push_back(p);
			break;
		}
		else{
			break;
		}
	}
	//horizontal-->left	
	for(i=position[1];i>0;i--){
		Coordinate p(position[0],i-1);
		if(!b.occupied(p)){
			moves.push_back(p);
		}
		else if(b.getPiece(p)->getColor() != this->getColor()){
			moves.push_back(p);
			break;
		} else{
			break;
		}

	}
	//vertical up
	for(i=position[0];i<7;i++){
		Coordinate p(i+1,position[1]);	
		if(!b.occupied(p)){
			moves.push_back(p);
		}
		else if(b.getPiece(p)->getColor() != this->getColor()){
			moves.push_back(p);
			break;
		}
		else{
			break;
		}

	}
	//vertical down
	for(i=position[0];i>0;i--){
		Coordinate p(i-1,position[1]);
		if(!b.occupied(p)){
			moves.push_back(p);
		}
		else if(b.getPiece(p)->getColor() != this->getColor()){
			moves.push_back(p);
			break;
		}
		else{
			break;
		}

	}
	
	return moves;
}




