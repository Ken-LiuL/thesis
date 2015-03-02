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

void Piece::setPosition(const int * p){
	if(position!=NULL){
		position[0] = p[0];
		position[1] = p[1];
	}
	else{
		
		position = new int[2];
		position[0] = p[0];
		position[1] =  p[1];
		delete[] p;
	    }
}
int *Piece::getPosition(){
	return position;
}
char Piece::getIdentifier(){
	return identifier;
}


