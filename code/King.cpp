#include "King.h"
#include <iostream>
#include "Board.h"
#include "Rook.h"
#include <cmath>
#include <vector>
#include "Constants.h"
using namespace std;

King::King(const char c,Coordinate p)
	:Piece::Piece('K',2000,c,p)	
	{
	neverMoved = TRUE;
}

Piece *King::copy(){
	return new King(this->color,position);
}
bool King::makeMove(const Coordinate toPosition,Board &board){
	vector<Coordinate> moves = this->legalMoves(board);
	bool isLegal = FALSE;
	for(vector<Coordinate>::iterator it=moves.begin();it<moves.end();it++){
		if((*it) == toPosition){
			isLegal = TRUE;
			/*check whether the move is castling*/
			if(abs((float)(this->getPosition()[1]-toPosition[1]))==2){
				if(toPosition[1]==2){
					Coordinate rookCord(toPosition[0],0);
					Piece* rook = board.getPiece(rookCord);
					rook->setPosition(Coordinate(toPosition[0],3));
				}
				else{
					Coordinate rookCord(toPosition[0],7);
					Piece* rook = board.getPiece(rookCord);
					rook->setPosition(Coordinate(toPosition[0],5));
				}	
			}
			this->setPosition(toPosition);	
			neverMoved =FALSE;
			break;
		}
	}
	
	return isLegal;	
}

vector<Coordinate> King::legalMovesWithoutCastling(const Board &board){
	vector<Coordinate> moves(0);
	Coordinate currentPosition = this->position;
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
		Coordinate cord(possibleMoves[i][0],possibleMoves[i][1]);
		if(cord.isInBoard())
		if(!board.occupied(cord)||(board.occupied(cord) && board.getPiece(cord)->getColor() != this->color))
				moves.push_back(cord);
	}
	return moves;

}

vector<Coordinate> King::legalMoves(const Board &board){
	vector<Coordinate> moves = this->legalMovesWithoutCastling(board);
	/*considering whether castling is possible*/
	if(neverMoved){
		/*check whether rooks has never been moved*/
		Coordinate cordRook1(this->position[0],0);
		Coordinate cordRook2(this->position[0],7);
		Rook *rook1 = (Rook*)board.getPiece(cordRook1);
		Rook *rook2 = (Rook*)board.getPiece(cordRook2);
		/*the king can not be checkmated*/
		if(board.isUnderAttack(this->position,this->color))
			return moves;
		/*check rook1*/
		if(rook1!=NULL &&  rook1->getColor()==this->color && rook1->getIdentifier()==ROOK && rook1->isNeverMoved()){
			Coordinate cord1(cordRook1[0],1);
			Coordinate cord2(cordRook1[0],2);
			Coordinate cord3(cordRook1[0],3);
			if(!board.occupied(cord1)&&!board.occupied(cord2)&&!board.occupied(cord3)){
				if(!board.isUnderAttack(cord3,this->color))
					moves.push_back(cord2);
			}

		}
		/*check rook2*/
		if(rook2!=NULL &&  rook2->getColor()==this->color && rook2->getIdentifier()==ROOK && rook2->isNeverMoved()){
		   	Coordinate cord1(cordRook2[0],5);
			Coordinate cord2(cordRook2[0],6);
			if(!board.occupied(cord1)&&!board.occupied(cord2))
			{
				if(!board.isUnderAttack(cord1,this->color))
					moves.push_back(cord2);
			}
		}
	}
	return moves;

	

}
