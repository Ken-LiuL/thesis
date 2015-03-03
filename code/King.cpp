#include "King.h"
#include <iostream>
#include "Board.h"
#include <vector>
#include "Constants.h"
using namespace std;

King::King(char c,int * p)
	:Piece::Piece('K',2000,c,p)	
	{}

bool King::makeMove(const int * toPosition,Board &b){
	vector<int*> moves = this->legalMoves(b);
	bool isLegal = FALSE;
	for(vector<int*>::iterator it=moves.begin();it<moves.end();it++){
		if((*it)[0]==toPosition[0] && (*it)[1]==toPosition[1]){
			isLegal = TRUE;
			this->setPosition(toPosition);	
		}
		delete[] (*it);
	}
	return isLegal;	
}


vector<int*> King::legalMoves(const Board &board){
	vector<int*> moves = vector<int*>();
	int * currentPosition = this->position;
	/*king can move one step horizontally, vertically and diagonall*/
	int possibleMoves[8][2] = {currentPosition[0]+1,currentPosition[1]
				  ,currentPosition[0]-1,currentPosition[1]
				  ,currentPosition[0],currentPosition[1]+1
				  ,currentPosition[0],currentPosition[1]-1
				  ,currentPosition[0]+1,currentPosition[1]+1				      ,currentPosition[0]+1,currentPosition[1]-1
				  ,currentPosition[0]-1,currentPosition[1]+1
				  ,currentPosition[0]-1,currentPosition[1]-1
				};
	
	/*remove position out of boundary and occupied by friend piece*/
	for(int i=0;i<8;i++){
		if(possibleMoves[i][0]<8 && possibleMoves[i][0]>-1 && possibleMoves[i][1]<8 && possibleMoves[i][1]>-1)
		if(!board.occupied(possibleMoves[i])||(board.occupied(possibleMoves[i]) && board.getPiece(possibleMoves[i])->getColor() != this->color)){
				int * cord = new int[2];
				cord[0] = possibleMoves[i][0];
				cord[1] = possibleMoves[i][1];
				moves.push_back(cord);
			}
	}
	/*considering whether castling is possible*/
	return moves;

	

}
