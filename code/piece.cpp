#include "piece.h"
#include <iostream>

Piece::Piece(char i,int v,char c,int * p){
	value = v;
	color = c;
        position = p;
	identifier = i;
}

int Piece::getValue(){
	return value;
}

char Piece::getColor(){
	return color;
}

void Piece::setPosition(int * p){
	position = p;
}
int *Piece::getPosition(){
	return position;
}
char Piece::getIdentifier(){
	return identifier;
}

void Piece::makeMove(int * toPosition){
	position = toPosition;
}
