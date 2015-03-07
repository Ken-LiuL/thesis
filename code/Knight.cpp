#include "Knight.h"
#include "Board.h"
#include "Constants.h"
#include <iostream>
using namespace std;

Knight::Knight(char c,int * p)
	:Piece::Piece('N',300,c,p)	
	{}

Piece *Knight::copy(){
	int *cord =new int[2];
	cord[0] =  this->position[0];
	cord[1] = this->position[1];
	return new Knight(this->color,cord);
}
bool Knight::makeMove(const int * toPosition, Board &b){
	vector<int*> moves = this->legalMoves(b);
	bool isLegal=FALSE;
	for(vector<int*>::iterator it=moves.begin();it<moves.end();it++){
		if(toPosition[0]==(*it)[0] && toPosition[1]==(*it)[1]){
			isLegal = TRUE;
			this->setPosition(toPosition);
		}
		delete[] (*it);
	}
	return isLegal;	
}


vector<int*> Knight::legalMoves(const Board &board){
	vector<int*> moves = vector<int*>();
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
		if(this->reachablePosition(possibleMoves[i],board)){
			int * c = new int[2];
			c[0] = possibleMoves[i][0];
			c[1] = possibleMoves[i][1];
			moves.push_back(c);
		}
	}
	return moves;
}

bool Knight::reachablePosition(const int * cord,const Board &board){
	/*check bouondary*/
	if(cord[0]<8 && cord[0] > -1 && cord[1]<8 && cord[1] > -1)
		/*check whether it is occupied by a friend piece*/
		if(!board.occupied(cord) || (board.occupied(cord) && board.getPiece(cord)->getColor() != this->color ))
			return TRUE;
	return FALSE;
}


