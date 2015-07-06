#include "ComputerPlayer.h"
#include "Board.h"
#include "Constants.h"
#include <vector>
#include <random>
#include <fstream>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "algorithm/Node.h"
#include "algorithm/Ep.h"

ComputerPlayer::ComputerPlayer(const char color){
	this->color = color;
	this->step = 0;
	//set seed of random generator
	this->seed.seed(std::random_device()());
}

/*random play strategy,select a random move from available moves. If draw,win or lose , return back. And we assume for WHITE player, draw is lose*/
char  ComputerPlayer::randomPlay(Board &board){
	std::vector<Board*> states=board.nextBoardStates(this->color);	
	char result;
	if(!states.empty()){
	   	std::uniform_int_distribution<std::mt19937::result_type> randomMove(0,states.size()-1);
		int move = randomMove(seed);
		board = *states[move];
		this->step += 1 ;
		if(board.checkWin(this->color)){
			result = this->color;
		}
		else
			result = CONTINUE;
	}
	else{
		result = BLACK;
	}

	for(int i=0;i<states.size();i++){
		delete states[i];
	}
	
	return result;
		
}

/*player establish a game tree and calculate G value for every node, and then choose its children node with largest G value, which means is more possible to win*/
char ComputerPlayer::algorithmPlay(Board &b){
	Distribution prior(0,1);
	Node root(b,prior,this->color);	
	root.setVisited();
	int i = 100;
	int counter = 0;
	while(i-->0){
		Ep::descent(root,counter);
	}
	std::vector<Node*>  children = root.getChildren();
	double largestV = -1000;
	
	Node * bestChild=NULL;
	for(std::vector<Node*>::iterator it=children.begin();it<children.end();it++){
		double v = (*it)->getVDis().getSample();
		if((*it)->getVDis().getVar()==0)
			continue;
		if(v > largestV){
			bestChild = (*it);	
			largestV = v;
		}	

	}
	if(bestChild == NULL){
		return  this->color==WHITE?BLACK:WHITE;
	}
	else{
		b = bestChild->getBoard();
		this->step +=1;
		if(b.checkWin(this->color))
			return this->color;
	}
	return CONTINUE;
}

char ComputerPlayer::getColor() const{
	return color;
}
void ComputerPlayer::setColor(const char color){
	this->color = color;
}
