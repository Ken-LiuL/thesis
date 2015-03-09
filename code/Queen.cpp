#include "Queen.h"
#include "Board.h"
#include "Constants.h"
#include <iostream>
using namespace std;

Queen::Queen(char c,Coordinate p)
	:Piece::Piece('Q',900,c,p)	
	{}

Piece *Queen::copy(){
	return new Queen(this->color,position);
}
bool Queen::makeMove(Coordinate toPosition,Board  &b){
	/*every move of queen is legal, so just to update its position
	so we just need to check whether target position has not been 
	occupied by friendly piece and has not been hindered by other pieces*/
	vector<Coordinate>  moveVector = this->legalMoves(b);
	bool isLegal =  FALSE;
	for(vector<Coordinate>::iterator it=moveVector.begin();it<moveVector.end();it++){
		if((*it)==toPosition){
			isLegal = TRUE;
			this->setPosition(toPosition);
			break;
		}
		
	}
	return isLegal;
}


vector<Coordinate> Queen::legalMoves(const Board &b){
	vector<Coordinate>  moves(0);
	//horizontal-->right
	int i,j;
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
		Coordinate  p(position[0],i-1);
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
	//northwest
	for(i=position[0],j=position[1];i<7 && j>0;i++,j--){
		Coordinate p(i+1,j-1);
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
	//northeast
	for(i=position[0],j=position[1];i<7 && j<7;i++,j++){
		Coordinate p(i+1,j+1);
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
	//southwest
	for(i=position[0],j=position[1];i>0 && j>0;i--,j--){
		Coordinate p(i-1,j-1);
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
	//southeast
	for(i=position[0],j=position[1];i>0 && j<7;i--,j++){
		Coordinate p(i-1,j+1);
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


