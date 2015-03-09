#include "ComputerPlayer.h"
#include "Constants.h"
#include "Board.h"
#include "piece.h"
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

ComputerPlayer::ComputerPlayer(char color,char strategy):Player::Player(color){
	this->strategy = strategy;
}

/*Random strategy used to test whether there are bugs,like memory leakage*/
void ComputerPlayer::play(Board &board){
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
		vector<int*> moves =  (pieces.at(j))->legalMoves(board);
		cout << pieces.at(j)->getPosition()[0] << "+" << pieces.at(j)->getPosition()[1] << endl;
		while(!moves.empty()){
			Board boardBackup =  board;
			i = rand() % moves.size();/*generate random move*/
			cout << "sec1: " << endl;
			pieces.at(j)->getPosition();
			cout << "sec1.5::::" << endl;
			bool t = boardBackup.makeMove((pieces.at(j))->getPosition(),moves.at(i));
			cout << "sec2:" << endl;
			if( t && (!amICheckmated(boardBackup))){
				board.makeMove((pieces.at(j))->getPosition(),moves.at(i));
				findMove = TRUE;
				break;
			}
			delete[] moves.at(i);
			moves.erase(moves.begin()+i);
		}
		for(int i=0;i<moves.size();i++){
			delete[] moves.at(i);
		}
		pieces.erase(pieces.begin()+j);
	}  
	if(findMove)
		return;
	cout << this->getColor() <<" lose" << endl ;
	exit(-1);
}

