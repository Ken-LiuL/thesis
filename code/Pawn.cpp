#include "Pawn.h"
#include "Board.h"
#include "Constants.h"
#include <iostream>
#include <stdlib.h>

Pawn::Pawn(char c,int * p):Piece::Piece('P',100,c,p){
	//this variable served for en passant,
	//and  whether a pawn can move forward two steps
	neverMoved = TRUE;	
}


//first test whether movement is legal, if it is legal , variable neverMoved needs to be set False,  then update the position and return true.And also if it is en passant , function Board::capture need be called to remove opponent's pawn. Furthermore, if it move forward two steps, function Board::setPassant is called to record that en passant is possible in next step.
bool Pawn::makeMove(int * toPosition,Board * board){
	int * currentPosition = position;
	bool isLegal  = FALSE;
	//if pawn want to move two steps forward, we need check whether it has nevermoved and whether there are no piece between its current position and desired postion and also there are no capture
	if(this->isMoveTwoSteps(toPosition)){
		int * middlePosition = new int[2];
		middlePosition[1]  =  currentPosition[1];
		middlePosition[0] =  (currentPosition[0]+toPosition[0])/2;
		
		if(neverMoved && !board->occupied(toPosition) && !board->occupied(middlePosition)){
			isLegal =  TRUE;
			neverMoved = FALSE;
			this->setPosition(toPosition);
			board->setPassant(this);
		}
		//free memory
		delete[] middlePosition;
	}
	//a pawn move forward one step is always permitted except the targetposition is occupied by self or opponent's piece
	else if(this->isMoveForward(toPosition) && !board->occupied(toPosition)){
		this->setPosition(toPosition);
		neverMoved = FALSE;
		isLegal = TRUE;
	}
	//a pawn can capture forward diagonally instead of direct forward
	else if(this->isCapture(toPosition) && board->occupied(toPosition) && board->getPiece(toPosition)->getColor() != this->getColor()){
		this->setPosition(toPosition);
		neverMoved = FALSE;
		isLegal = TRUE;
	}
	// SEE  whether en passant is possible
	else if(this->isCapture(toPosition)){
		Board::EnPassant * ep = board->getPassant();
		//check whether en-passant is possible
		if(ep->p!=NULL && ep->step == board->currentStep()){
			char color = ep->p->getColor();
			int * p1 = ep->p->getPosition();
			int * p2 = new int[2];
			p2[1] = p1[1];
			if(color==WHITE)
				p2[0] = p1[0]-1;
			else		
				p2[0] = p1[0]+1;
			//test whether target position is the right postion to make en passant
			if(p2[0]==toPosition[0] && p2[1]==toPosition[1]){
				this->setPosition(toPosition);
				neverMoved = FALSE;
				board->capture(ep->p->getPosition(),ep->p->getPosition());
				isLegal = TRUE;
			}
			delete[] p2;
		}
	}
	return isLegal;
}

bool Pawn::isMoveForward(int * toPosition){
	int * currentPosition = position;
	if(this->getColor()==WHITE){
		if(currentPosition[1] == toPosition[1] && toPosition[0]-currentPosition[0] ==1)
			return TRUE;
		else
			return FALSE;	

	}
	else{
		if(currentPosition[1] == toPosition[1] && currentPosition[0]-toPosition[0] ==1)
			return TRUE;
		else
			return FALSE;
	}
}

bool Pawn::isMoveTwoSteps(int *toPosition){
	int * currentPosition = position;
	if(this->getColor()==WHITE){
		if(currentPosition[1]==toPosition[1] && toPosition[0]-currentPosition[0] == 2)
			return TRUE;
		else
			return FALSE;
	}
	else{
		if(currentPosition[1]==toPosition[1] && currentPosition[0]-toPosition[0]==2)
			return TRUE;
		else
			return FALSE;

	}

}

bool Pawn::isCapture(int * toPosition){
	int * currentPosition = position;
	if(this->getColor() == WHITE){
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

int ** Pawn::legalMoves(){
	
	return NULL;

}


