#include "HumanPlayer.h"
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
		if(boardBackup.makeMove(from,to) && ! this->beCheckmated(boardBackup)){ 	
			board.makeMove(from,to);
		}		
		else
			cout << "error movement"<< endl;
	}
	delete[] from;
	delete[] to;

}

bool HumanPlayer::beCheckedmated(Board &board){
	vector<Piece*> pieces = board.getPieces();
	vector<int*> opponentAttack = vector<int*>();
	int i,j;
	int * positionOfKing ; 
	for(i=0;i<pieces.size();i++){
		if(pieces.at(i)->getColor()==this->color && pieces.at(i)->getIdentifier() == KING)
			positionOfKing = pieces.at(i)->getPosition();
		else if(pieces.at(i)->getColor()!=this->color()){
			

		}
	}
}
