#include "Pawn.h"
#include "Board.h"
#include "Constants.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

Pawn::Pawn(const char c,Coordinate p):Piece::Piece('P',100,c,p){
	/*this variable served for en passant,
	and  whether a pawn can move forward two step */
	neverMoved = TRUE;	
}


Piece *Pawn::copy(){
	return new Pawn(this->color,position);
}

bool Pawn::isNeverMoved() const{
	return neverMoved;
}
/*first test whether movement is legal, if it is legal , variable neverMoved needs to be set False,  then update the position and return true.And also if it is en passant , function Board::capture need be called to remove opponent's pawn. Furthermore, if it move forward two steps, function Board::setPassant is called to record that en passant is possible in next step.*/
bool Pawn::makeMove(const Coordinate toPosition,Board &board){
	vector<Coordinate> moves =  this->legalMoves(board);
	
	Coordinate currentPosition = this->position;
	bool isLegal  = FALSE;
	for(vector<Coordinate>::iterator it=moves.begin();it<moves.end();it++){
		if((*it) == toPosition){
			isLegal = TRUE;
			this->neverMoved = FALSE;
			break;
		}
		
	}
	if(isLegal){
		/*if a pawn move two steps en passant need to be set*/
		if(isLegal && this->isMoveTwoSteps(toPosition)){
			board.setPassant(this);
		}
	
		/* SEE  the move is en passant  */
		else if(isLegal && this->isCapture(toPosition) && !board.occupied(toPosition)){
			Board::EnPassant * ep = board.getPassant();
			board.capture(ep->p->getPosition(),ep->p->getPosition());
		 }
		this->setPosition(toPosition);
	}

	/*check whether promotion is needed*/
	if(this->canPromote())
		board.doPromotion(this);

	return isLegal;
}

/*see wheterh a promotion is possbile by checking whether it hit the bottom of opponent*/
bool Pawn::canPromote(){
	Coordinate currentPosition = this->position;
	if(this->color ==WHITE && currentPosition[0]==7)
		return TRUE;	
	else if(this->color ==BLACK && currentPosition[0]==0)
			return TRUE;
		
	return FALSE;
}

/*below three functions are used to check what the king of move it is*/

bool Pawn::isMoveForward(const Coordinate toPosition){
	Coordinate currentPosition = this->position;
	if(this->color ==WHITE){
		if(currentPosition == Coordinate(toPosition[0]-1,toPosition[1]))
			return TRUE;
		else
			return FALSE;	

	}
	else{
		if(currentPosition == Coordinate(toPosition[0]+1,toPosition[1]))
			return TRUE;
		else
			return FALSE;
	}
}

bool Pawn::isMoveTwoSteps(const Coordinate toPosition){
	Coordinate currentPosition = this->position;
	if(this->color ==WHITE){
		if(currentPosition == Coordinate(toPosition[0]-2,toPosition[1]))
			return TRUE;
		else
			return FALSE;
	}
	else{
		if(currentPosition == Coordinate(toPosition[0]+2,toPosition[1]))
			return TRUE;
		else
			return FALSE;

	}

}


bool Pawn::isCapture(const Coordinate  toPosition){
	Coordinate currentPosition = this->position;
	if(this->color == WHITE){
		if(abs(currentPosition[1]-toPosition[1])==1 && toPosition[0]-currentPosition[0]==1)
			return TRUE;
		else
			return FALSE; 
	}
	else{
		if(abs(currentPosition[1]-toPosition[1])==1 && currentPosition[0]-toPosition[0]==1)
			return TRUE;
		else
			return FALSE; 
	}
}

vector<Coordinate> Pawn::legalMoves(const Board &board){
	vector<Coordinate> moves(0);
	
	/*forward one step*/
 	Coordinate  target; 
	target[0] = this->color == WHITE ? this->position[0]+1:this->position[0]-1;
	target[1] = this->position[1];
	if(target.isInBoard() && !board.occupied(target))
		moves.push_back(target);

	/*forward two steps*/
	if(neverMoved){
		Coordinate twoStep; 
		twoStep[0] = this->color == WHITE ? this->position[0]+2 : this->position[0]-2;
		twoStep[1] = this->position[1];
		Coordinate middle = Coordinate((this->position[0]+twoStep[0])/2,twoStep[1]);
		if(twoStep.isInBoard() && !board.occupied(middle) && !board.occupied(target))
			moves.push_back(twoStep);

	}
	/*capture*/
	Coordinate left;
	left[0] = this->color == WHITE ? this->position[0]+1 : this->position[0]-1;
	left[1] = this->position[1]-1;
	
	if(left.isInBoard() && board.occupied(left) && board.getPiece(left)->getColor()!=this->color)
		moves.push_back(left);

	Coordinate right = Coordinate();
	right[0] = this->color == WHITE ? this->position[0]+1: this->position[0]-1;
	right[1] = this->position[1]+1;
	if(right.isInBoard() && board.occupied(right) && board.getPiece(right)->getColor()!=this->color)
		moves.push_back(right);

	/*en passant*/
	Board::EnPassant * ep = board.getPassant();
	/*check whether en-passant is possible */
	if(ep->p!=NULL && ep->step == board.currentStep()){
		char color = ep->p->getColor();
		Coordinate p1 = ep->p->getPosition();
		if(color==WHITE)
			p1[0] = p1[0]-1;
		else		
			p1[0] = p1[0]+1;
		/*test whether position p2 is reachable*/
		if(this->color==WHITE && p1[0]-this->position[0]==1 && abs(p1[1]-this->position[1])==1)
			moves.push_back(p1);
		else if(this->color==BLACK && p1[0]-this->position[0]==-1 && abs(p1[1]-this->position[1])==1)
			moves.push_back(p1);
	}
	
	return moves;

}

