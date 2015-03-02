#include "Pawn.h"
#include "Board.h"
#include "Constants.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

Pawn::Pawn(char c,int * p):Piece::Piece('P',100,c,p){
	/*this variable served for en passant,
	and  whether a pawn can move forward two step */
	neverMoved = TRUE;	
}


/*first test whether movement is legal, if it is legal , variable neverMoved needs to be set False,  then update the position and return true.And also if it is en passant , function Board::capture need be called to remove opponent's pawn. Furthermore, if it move forward two steps, function Board::setPassant is called to record that en passant is possible in next step.*/
bool Pawn::makeMove(const int * toPosition,Board &board){
	vector<int*> moves =  this->legalMoves(board);
	int * currentPosition = this->position;
	bool isLegal  = FALSE;
	for(vector<int*>::iterator it=moves.begin();it<moves.end();it++){
		if((*it)[0] == toPosition[0] && (*it)[1] == toPosition[1]){
			isLegal = TRUE;
			this->neverMoved = FALSE;
		}
		/*free memory*/
		delete[] (*it);
		
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
	int * currentPosition = this->position;
	if(this->color ==WHITE && currentPosition[0]==7)
		return TRUE;	
	else if(this->color ==BLACK && currentPosition[0]==0)
			return TRUE;
		
	return FALSE;
}

/*below three functions are used to check what the king of move it is*/

bool Pawn::isMoveForward(const int * toPosition){
	int * currentPosition = this->position;
	if(this->color ==WHITE){
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

bool Pawn::isMoveTwoSteps(const int *toPosition){
	int * currentPosition = this->position;
	if(this->color ==WHITE){
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


bool Pawn::isCapture(const int * toPosition){
	int * currentPosition = this->position;
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

vector<int*> Pawn::legalMoves(const Board &board){
	vector<int*> moves  = vector<int*>();
	
	/*forward one step*/
 	int * target = new int[2];
	target[0] = this->color == WHITE ? this->position[0]+1:this->position[0]-1;
	target[1] = this->position[1];
	if(target[0]<8 && target[0] >-1 && !board.occupied(target))
		moves.push_back(target);
	else
		delete[] target;
	/*forward two steps*/
	if(neverMoved){
		target = new int[2];
		target[0] = this->color == WHITE ? this->position[0]+2 : this->position[0]-2;
		target[1] = this->position[1];
		int middle[2] = {(this->position[0]+target[0])/2,target[1]};
		if(target[0]<8 && target[0] > -1 && !board.occupied(middle) && !board.occupied(target)){
			moves.push_back(target);
		}
		else
			delete[] target;

	}
	/*capture*/
	int * left = new int[2];
	left[0] = this->color == WHITE ? this->position[0]+1 : this->position[0]-1;
	left[1] = this->position[1]-1;
	
	if(left[0]<8 && left[0]>-1 && left[1]>-1 && left[1]<8 && board.occupied(left) && board.getPiece(left)->getColor()!=this->color)
		moves.push_back(left);
	else
		delete[] left;

	int * right = new int[2];
	right[0] = this->color == WHITE ? this->position[0]+1: this->position[0]-1;
	right[1] = this->position[1]+1;
	if(right[0]<8 && right[0]>-1 && right[1]<8 && right[1]>-1 && board.occupied(right) && board.getPiece(right)->getColor()!=this->color)
		moves.push_back(right);
	else
		delete[] right;
	/*en passant*/
	Board::EnPassant * ep = board.getPassant();
	/*check whether en-passant is possible */
	if(ep->p!=NULL && ep->step == board.currentStep()){
		char color = ep->p->getColor();
		int * p1 = ep->p->getPosition();
		int * p2 = new int[2];
		p2[1] = p1[1];
		if(color==WHITE)
			p2[0] = p1[0]-1;
		else		
			p2[0] = p1[0]+1;
		/*test whether position p2 is reachable*/
		if(this->color==WHITE && p2[0]-this->position[0]==1 && abs(p2[1]-this->position[1])==1)
			moves.push_back(p2);
		else if(this->color==BLACK && p2[0]-this->position[0]==-1 && abs(p2[1]-this->position[1])==1)
			moves.push_back(p2);
		else
			delete[] p2;
	}
	
	return moves;

}

