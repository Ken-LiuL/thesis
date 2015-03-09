#include "piece.h"
#include <iostream>

Piece::Piece(char i,int v,char c,Coordinate p){
	value = v;
	color = c;
        position = p;
	identifier = i;
}

int Piece::getValue() const{
	return value;
}

char Piece::getColor() const{
	return color;
}

void Piece::setPosition(const Coordinate &p){
	position[0] = p[0];
	position[1] = p[1];
		
}
const Coordinate &Piece::getPosition() const{
	return position;
}
char Piece::getIdentifier() const{
	return identifier;
}



