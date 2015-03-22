#include "Player.h"
#include "Board.h"
#include "piece.h"
#include "Constants.h"
#include <vector>
using namespace std;
Player::Player(const char color){
	this->color =color;
}

char Player::getColor(){
	return color;
}
