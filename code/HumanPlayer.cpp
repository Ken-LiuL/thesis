#include "HumanPlayer.h"
#include "King.h"
#include "Board.h"
#include "piece.h"
#include "Constants.h"
#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;

HumanPlayer::HumanPlayer(char c){
	color = c;
	checkmated = FALSE;
}

void HumanPlayer::humanPlay(Board &board){	
	/*parse command from human*/
	string command;
	getline(cin,command);
	if(command=="abort" || command=="quit"){
		exit(1);
	}
	int a,b,c,d;
	a = command[0]-'a';
	b = command[1]-'1';
	c = command[2] - 'a';
	d = command[3] - '1';
		
	int * from = new int[2];
	int * to = new int[2];
	from[0] = b;
	from[1] = a;
	to[0] = d;
	to[1] = c;
	/*check whether currently human is under checkmate*/
	if(this->checkmated){
		;	
	
	}
	else{
		Board boardBackup = board;
		if(boardBackup.makeMove(from,to) && !beCheckmated(boardBackup)){ 	
			board.makeMove(from,to);
		}		
		else
			exit(-1);
	}
	delete[] from;
	delete[] to;

}

bool HumanPlayer::beCheckmated(Board &board){
	vector<Piece*> pieces = board.getPieces();
	vector<int*> opponentAttack;
	int i;
	int * positionOfKing; 
	bool  checkMated = FALSE;
	for(i=0;i<pieces.size();i++){
		if(pieces.at(i)->getColor()==this->color && pieces.at(i)->getIdentifier() == KING){
			positionOfKing = pieces.at(i)->getPosition();
			break;
			}
			
	}
	return board.isUnderAttack(positionOfKing,this->color);
}
