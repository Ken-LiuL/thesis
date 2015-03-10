#include "Bishop.h"
#include "Constants.h"
#include "Board.h"
#include <iostream>
using namespace std;

Bishop::Bishop(const char c,Coordinate p)
	:Piece::Piece('B',300,c,p)	
	{}

Piece *Bishop::copy(){
	return new Bishop(this->color,position);
}
bool Bishop::makeMove(const Coordinate toPosition,Board &b){
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

vector<Coordinate> Bishop::legalMoves(const Board &b){
	vector<Coordinate> moves(0);
	int i,j;
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



