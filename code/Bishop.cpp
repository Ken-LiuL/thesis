#include "Bishop.h"
#include <iostream>
using namespace std;

Bishop::Bishop(char c,int * p)
	:Piece::Piece('B',300,c,p)	
	{}

Piece *Bishop::copy(){
	int *cord = new int[2];
	cord[0] = this->position[0];
	cord[1] = this->position[1];
	return new Bishop(this->color,cord);
}
bool Bishop::makeMove(const int * toPosition,Board &b){
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

vector<int*> Bishop::legalMoves(const Board &board){
	vector<int*> moves  = vector<int*>();
	int i,j;
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


