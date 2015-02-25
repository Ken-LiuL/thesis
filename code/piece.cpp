#include "piece.h"
#include <iostream>

Piece::Piece(int v,char c,int * p){
	value = v;
	color = c;
        position = p;
}

int Piece::getValue(){
	return value;
}

char Piece::getColor(){
	return color;
}

int *Piece::getPosition(){
	return position;
}


