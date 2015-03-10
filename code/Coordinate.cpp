#include "Coordinate.h"
#include "Constants.h"

Coordinate::Coordinate(const int x, const int y){
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
	else
		return FALSE;
}

void Coordinate::update(const Coordinate &cord){
	rank = cord.getRank();
	col = cord.getCol();
}

int Coordinate::operator [](const int i) const{
	return i==0 ? rank : col;
}

bool Coordinate::operator==(const Coordinate cord) const{
	if(cord[0]==(*this)[0] && cord[1]== (*this)[1])
		return TRUE;
	else
		return FALSE;
}

int & Coordinate::operator [](const int i){
	return i==0 ? rank : col;
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

