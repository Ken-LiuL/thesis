#include "ComputerPlayer.h"
#include "Constants.h"
#include "Board.h"
#include "piece.h"
#include "algorithm/Node.h"
#include "algorithm/Ep.h"
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

ComputerPlayer::ComputerPlayer(const char color,const char strategy):Player::Player(color){
	this->strategy = strategy;
}

void ComputerPlayer::play(Board &board){
	if(this->strategy=='R')
		randomPlay(board);
	else{
		algorithmPlay(board);
	}

}

void ComputerPlayer::algorithmPlay(Board &board){
	/*set v0,m0 as 1,0 for root*/
	Distribution prior(0,1);
	Node root(board,prior,this->color);
	root.sampleG();
	
	root.setVisited();
	while(true){
		
		Ep::descent(root);	

	}	

}



/*Random strategy used to test whether there are bugs,like memory leakage*/
void ComputerPlayer::randomPlay(Board &board){
 	srand(time(NULL));
	vector<Piece*> p = board.getPieces();
	vector<Piece*> pieces = vector<Piece*>(0);
	/*get pieces belong to itself*/
	for(vector<Piece*>::iterator it=p.begin();it<p.end();it++){
		if((*it)->getColor()==this->getColor())
			pieces.push_back((*it));
	}
	bool findMove = FALSE;
	int i,j;
	while(!pieces.empty()){
		j = rand() % pieces.size();/*generate random piece*/
		if(findMove)
			break;
		vector<Coordinate> moves =  (pieces.at(j))->legalMoves(board);
		while(!moves.empty()){
			Board boardBackup =  board;
			i = rand() % moves.size();/*generate random move*/
			pieces.at(j)->getPosition();
			bool t = boardBackup.makeMove((pieces.at(j))->getPosition(),moves.at(i));
			if( t && (!boardBackup.amICheckmated(this->color))){
				board.makeMove((pieces.at(j))->getPosition(),moves.at(i));
				findMove = TRUE;
				break;
			}
			moves.erase(moves.begin()+i);
		}
		pieces.erase(pieces.begin()+j);
	}  
	if(findMove)
		return;
	cout << this->getColor() <<" lose" << endl ;
	exit(0);
}

