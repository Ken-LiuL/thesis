#include "HumanPlayer.h"
#include "King.h"
#include "Board.h"
#include "piece.h"
#include "Constants.h"
#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;

HumanPlayer::HumanPlayer(const char c):Player::Player(c){
}

void HumanPlayer::play(Board &board){	
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
		
	Coordinate from =  Coordinate();
	Coordinate to = Coordinate();
	from[0] = b;
	from[1] = a;
	to[0] = d;
	to[1] = c;
	
	Board boardBackup = board;
	if((board.getPiece(from)->getColor()==this->getColor()) && boardBackup.makeMove(from,to) && !amICheckmated(boardBackup))
		board.makeMove(from,to);
	else
		cout << "error message " << endl;

}


