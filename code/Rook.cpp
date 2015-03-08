#include "Rook.h"
#include "Board.h"
#include <iostream>
#include "Constants.h"
using namespace std;

Rook::Rook(char c,int * p)
	:Piece::Piece('R',500,c,p)	
	{
	neverMoved = TRUE;
}

Piece *Rook::copy(){
	int *cord = new int[2];
	cord[0] = this->position[0];
	cord[1] = this->position[1];
	return new Rook(this->color,cord);
}

bool Rook::isNeverMoved(){
	return neverMoved;
}
bool Rook::makeMove(const int * toPosition, Board &b){
	/*check whether toPosition is in legalMoves, and free memory in moveVector*/
	vector<int*>  moveVector = this->legalMoves(b);
	bool isLegal =  FALSE;
	for(vector<int*>::iterator it=moveVector.begin();it<moveVector.end();it++){
		if(toPosition[0]==(*it)[0] && toPosition[1]==(*it)[1]){
			isLegal = TRUE;
			this->setPosition(toPosition);
			neverMoved = FALSE;
		}
		delete[] *it;
	}
	return isLegal;

}

vector<int*> Rook::legalMoves(const Board &b){
	vector<int*>  moves =  vector<int*>(0);
	//horizontal-->right
	int i,j;
	for(i=position[1];i<7;i++){
		int * p  = new int[2];
		p[0] = position[0];
		p[1] = i+1;
		if(!b.occupied(p)){
			moves.push_back(p);
		}
		else if(b.getPiece(p)->getColor() != this->getColor()){
			moves.push_back(p);
			break;
		}
		else{
			delete[] p;
			break;
		}
	}
	//horizontal-->left	
	for(i=position[1];i>0;i--){
		int * p = new int[2];
		p[0] = position[0];
		p[1] = i-1;
		if(!b.occupied(p)){
			moves.push_back(p);
		}
		else if(b.getPiece(p)->getColor() != this->getColor()){
			moves.push_back(p);
			break;
		}
		else{
			delete[] p;
			break;
		}

	}
	//vertical up
	for(i=position[0];i<7;i++){
		int * p = new int[2];
		p[1] = position[1];
		p[0] = i+1;
		if(!b.occupied(p)){
			moves.push_back(p);
		}
		else if(b.getPiece(p)->getColor() != this->getColor()){
			moves.push_back(p);
			break;
		}
		else{
			delete[] p;
			break;
		}

	}
	//vertical down
	for(i=position[0];i>0;i--){
		int * p = new int[2];
		p[1] = position[1];
		p[0] = i-1;
		if(!b.occupied(p)){
			moves.push_back(p);
		}
		else if(b.getPiece(p)->getColor() != this->getColor()){
			moves.push_back(p);
			break;
		}
		else{
			delete[] p;
			break;
		}

	}
	return moves;

}




