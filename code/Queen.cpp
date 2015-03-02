#include "Queen.h"
#include "Board.h"
#include "Constants.h"
#include <iostream>
using namespace std;

Queen::Queen(char c,int * p)
	:Piece::Piece('Q',900,c,p)	
	{}

bool Queen::makeMove(const int * toPosition,Board  &b){
	/*every move of queen is legal, so just to update its position
	so we just need to check whether target position has not been 
	occupied by friendly piece and has not been hindered by other pieces*/
	vector<int*>  moveVector = this->legalMoves(b);
	bool isLegal =  FALSE;
	for(vector<int*>::iterator it=moveVector.begin();it<moveVector.end();it++){
		if(toPosition[0]==(*it)[0] && toPosition[1]==(*it)[1]){
			isLegal = TRUE;
			this->setPosition(toPosition);
		}
		delete[] *it;
	}
	return isLegal;
}


vector<int*> Queen::legalMoves(const Board &b){
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
	//northwest
	for(i=position[0],j=position[1];i<7 && j>0;i++,j--){
		int * p = new int[2];
		p[0] = i+1;
		p[1] = j-1;
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
	//northeast
	for(i=position[0],j=position[1];i<7 && j<7;i++,j++){
		int * p = new int[2];
		p[0] = i+1;
		p[1] = j+1;
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
	//southwest
	for(i=position[0],j=position[1];i>0 && j>0;i--,j--){
		int * p = new int[2];
		p[0] = i-1;
		p[1] = j-1;
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
	//southeast

	for(i=position[0],j=position[1];i>0 && j<7;i--,j++){
		int * p = new int[2];
		p[0] = i-1;
		p[1] = j+1;
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


