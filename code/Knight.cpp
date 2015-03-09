#include "Knight.h"
#include "Board.h"
#include "Constants.h"
#include <iostream>
using namespace std;

Knight::Knight(char c,Coordinate p)
	:Piece::Piece('N',300,c,p)	
	{}

Piece *Knight::copy(){
	return new Knight(this->color,position);
}
bool Knight::makeMove(Coordinate toPosition, Board &b){
	vector<Coordinate> moves = this->legalMoves(b);
	bool isLegal=FALSE;
	for(vector<Coordinate>::iterator it=moves.begin();it<moves.end();it++){
		if((*it)==toPosition){
			isLegal = TRUE;
			this->setPosition(toPosition);
			break;
		}
	}
	return isLegal;	
}


vector<Coordinate> Knight::legalMoves(const Board &board){
	vector<Coordinate> moves(0);
	//horizontal left
	int left[2] = {this->position[0],this->position[1]-2};
	int left_up[2] = {left[0]+1,left[1]};
	int left_down[2] = {left[0]-1,left[1]};
	//horizontal right
	int right[2] = {this->position[0],this->position[1]+2};
	int right_up[2] = {right[0]+1,right[1]};
	int right_down[2] = {right[0]-1,right[1]};
	//vertical up
	int up[2] = {this->position[0]+2,this->position[1]};
	int up_left[2] = {up[0],up[1]-1};
	int up_right[2] = {up[0],up[1]+1};
	//vertical down
	int down[2] = {this->position[0]-2,this->position[1]};
	int down_left[2] = {down[0],down[1]-1};
	int down_right[2] = {down[0],down[1]+1};


	int possibleMoves[8][2] = {left_up[0],left_up[1]
				   ,left_down[0],left_down[1]						       ,right_up[0],right_up[1]
				   ,right_down[0],right_down[1]
				   ,up_left[0],up_left[1]
				   ,up_right[0],up_right[1]
				   ,down_left[0],down_left[1]
				   ,down_right[0],down_right[1]
					};

	/*check whether these positions are reachable*/
	for(int i=0;i<8;i++){
		Coordinate cord(possibleMoves[i][0],possibleMoves[i][1]);
		if(cord.isInBoard() && this->reachablePosition(cord,board)){
			moves.push_back(cord);
		}
	}
	return moves;
}

bool Knight::reachablePosition(Coordinate cord,const Board &board){
	/*check whether it is occupied by a friend piece*/
	if(!board.occupied(cord) || (board.occupied(cord) && board.getPiece(cord)->getColor() != this->color ))
		return TRUE;
	return FALSE;
}


