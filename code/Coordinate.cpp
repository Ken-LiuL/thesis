#include "Coordinate.h"
#include "Constants.h"

Coordinate::Coordinate(int x, int y){
	 rank = x;
	 col = y;
}

Coordinate::Coordinate(){
	rank = 0;
	col = 0;
}

bool Coordinate::isInBoard() const{
	if(rank<8 && rank>-1 && col<8 && col>-1)
		return TRUE;
}
void Coordinate::update(const Coordinate &cord){
	rank = cord.getRank();
	col = cord.getCol();
}

int Coordinate::getRank() const{
	return rank;
}

int Coordinate::getCol() const{
	return col;
}

void Coordinate::setRank(const int x){
	rank = x;
}

void Coordinate::setCol(const int y){
	col = y;
}
