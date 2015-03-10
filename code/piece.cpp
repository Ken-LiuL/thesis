#include "piece.h"
#include <iostream>

Piece::Piece(const char i,const int v,const char c,Coordinate p){
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

void Piece::setPosition(const Coordinate p){
	position[0] = p[0];
	position[1] = p[1];
		
}
Coordinate Piece::getPosition() const{
	return position;
}
char Piece::getIdentifier() const{
	return identifier;
}



