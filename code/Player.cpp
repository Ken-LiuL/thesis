#include "Player.h"
#include "Board.h"
#include "piece.h"
#include "Constants.h"
#include <vector>
using namespace std;
Player::Player(const char color){
	this->color =color;
}

bool Player::amICheckmated(Board &board,char color){
	vector<Piece*> pieces = board.getPieces();
	vector<Coordinate> opponentAttack;
	Coordinate positionOfKing; 
	for(int i=0;i<pieces.size();i++){
		if((pieces.at(i)->getColor()==color) && (pieces.at(i)->getIdentifier() == KING)){
			positionOfKing = pieces.at(i)->getPosition();
			break;
			}
			
	}
	return board.isUnderAttack(positionOfKing,color);

}

char Player::getColor(){
	return color;
}
