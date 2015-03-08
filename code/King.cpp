#include "King.h"
#include <iostream>
#include "Board.h"
#include "Rook.h"
#include <vector>
#include "Constants.h"
using namespace std;

King::King(char c,int * p)
	:Piece::Piece('K',2000,c,p)	
	{
	neverMoved = TRUE;
}

Piece *King::copy(){
	int * cord = new int[2];
	cord[0] = this->position[0];
	cord[1] = this->position[1];
	return new King(this->color,cord);
}
bool King::makeMove(const int * toPosition,Board &b){
	vector<int*> moves = this->legalMoves(b);
	bool isLegal = FALSE;
	for(vector<int*>::iterator it=moves.begin();it<moves.end();it++){
		if((*it)[0]==toPosition[0] && (*it)[1]==toPosition[1]){
			isLegal = TRUE;
			this->setPosition(toPosition);	
			neverMoved =FALSE;
		}
		delete[] (*it);
	}
	return isLegal;	
}

vector<int*> King::legalMovesWithoutCastling(const Board &board){
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
	return moves;

}

vector<int*> King::legalMoves(const Board &board){
	vector<int*> moves = this->legalMovesWithoutCastling(board);
	/*considering whether castling is possible*/
	if(neverMoved){
		/*check whether rooks has never been moved*/
		int cordRook1[] = {this->position[0],0};
		int cordRook2[] = {this->position[0],7};
		Piece *rook1 = board.getPiece(cordRook1);
		Piece *rook2 = board.getPiece(cordRook2);
		if(rook1!=NULL && rook1->getColor()==this->color && rook1.getIdentifier()==ROOK && rook1.isNeverMoved()){
			int cord1[] = {cordRook1[0],1};
			int cord2[] = {cordRook1[0],2};
			int cord3[] = {cordRook1[0],3};
			if(!board.occupied(cord1)&&!board.occupied(cord2)&&!board.occupied(cord3)){
				;

	
			}

		}
		if(rook2!=NULL && rook2->getColor()==this->color && rook2.getIdentifier()==ROOK && rook1.isNeverMoved()){
		   	int cord1[] = {cordRook2[0],5};
			int cord2[] = {cordRook2[0],6};
			if(!board.occupied(cord1)&&!board.occupied(cord2))
				;
		}
	}
	return moves;

	

}
