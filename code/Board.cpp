#include <string>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <iostream>
#include "Constants.h"
#include "Board.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"
#include "Pawn.h"
#include "Knight.h"
#include "Rook.h"
#include "HumanPlayer.h"
using namespace std;

/*This class mainly relate with interaction between board display and pieceschanges under different moves*/

Board::Board(int n,vector<Piece *> p){
	pieces = p; /* list that contains pointers of pieces on the board */
	passant = new Board::EnPassant(); /* struct { Piece * and step} */
	steps = 0;/* record how many steps has been so far */
}

/*destructor , free memory of piece and passant*/
Board::~Board(){
	for(vector<Piece*>::iterator it=pieces.begin();it<pieces.end();it++)
	{
		delete (*it);
	}
}

Board::Board(Board &b){
	steps = b.currentStep();
        vector<Piece*> &piecesB = b.getPieces();
	pieces = vector<Piece*>(0);
	for(vector<Piece*>::iterator it=piecesB.begin();it<piecesB.end();it++){
	
		pieces.push_back((*it)->copy());
		
	}
}
void Board::freshBoard(){
	int i,j;
	int l  = 8;
        for(i=0;i<l;i++)
		for(j=0;j<l;j++)
			board[i][j] = NULL;
	for(i=0;i<pieces.size();i++){
		int * p = pieces.at(i)->getPosition();
		board[p[0]][p[1]] = pieces.at(i); 

	}
}
/*currently text mode display */
void Board::display(){
	using namespace std;
	int i,j;
	/*initialization of the board */
	int l  = 8;
	this->freshBoard();
        /*display*/
	for(i=l-1;i>-1;i--){
		for(j=0;j<l;j++){
			string output = "";
			if(board[i][j]==NULL)
				output = "X  ";
			else if(board[i][j]->getColor() == BLACK){
				string black  = "B_";
				output = black + board[i][j]->getIdentifier();
			}
			else{
				string white = "W_";
				output = white +  board[i][j]->getIdentifier();
			}
			cout << output << " ";
		}	
			cout << endl;
		}
		cout << endl << endl;

}

void Board::initialize(){
	//instantiate 32 piecess
      	int i=0,j=0;
	
      	pieces.push_back(new Rook(WHITE,NULL));
     	pieces.push_back(new Knight(WHITE,NULL));
	pieces.push_back(new  Bishop(WHITE,NULL));
	pieces.push_back(new Queen(WHITE,NULL));
        pieces.push_back(new King(WHITE,NULL));
	pieces.push_back(new Bishop(WHITE,NULL));
     	pieces.push_back(new Knight(WHITE,NULL));
      	pieces.push_back(new Rook(WHITE,NULL));
        for(;j<16;j++){
		if(j<8)
			pieces.push_back(new Pawn(WHITE,NULL));
		else
			pieces.push_back(new Pawn(BLACK,NULL));
     	 }
	
      	pieces.push_back(new Rook(BLACK,NULL));
     	pieces.push_back(new Knight(BLACK,NULL));
	pieces.push_back(new Bishop(BLACK,NULL));
	pieces.push_back(new Queen(BLACK,NULL));
	pieces.push_back(new King(BLACK,NULL));
	pieces.push_back(new Bishop(BLACK,NULL));
     	pieces.push_back(new Knight(BLACK,NULL));
      	pieces.push_back(new Rook(BLACK,NULL));
	
	/*set the position of these piecess */
        for(i=0;i<16;i++){
	       	int * l =  new int[2];
	       	l[0] = i/8;
	       	l[1] = i%8;
	       	pieces.at(i)->setPosition(l);
	}
	for(i=48;i<64;i++){
		int * l = new int[2];
		l[0] = i/8;
		l[1] = i%8;
		pieces.at(i-32)->setPosition(l); 
	}

	
}

/*whether a borad sqaure is empty or occupied by a piece */
bool Board::occupied(const int * position) const{
	if(board==NULL)
		exit(-1) ;
	if(board[position[0]][position[1]]==NULL)
		return FALSE;
	else
		return TRUE;
}

/* if a move is legal then make a move, return true */
bool Board::makeMove(int * from, int * to){
	if(from[0]<8 && from[0]>-1 && from[1]>-1 && from[1]<8 && to[0]<8 && to[0]>-1 && to[1]<8 && to[1]>-1){
		Piece * p = board[from[0]][from[1]];
		
		if(p!=NULL){
			if(p->makeMove(to,*this)){
				/*if is a capture move,then list pieces and variable need to be updated */
				if(this->getPiece(to)!=NULL)
					this->capture(from,to);
				
				this->increaseSteps();

				return TRUE;
			}
		}
	}
	return FALSE;

}

/*update variable board and delete target piece from list pieces and also
from memory of that piece*/
void Board::capture(int *from,int * to){
	Piece * p = this->getPiece(to);
	for(int i=0;i<pieces.size();i++){
		if(pieces.at(i)==p){
			/*free memory,decremental variable numberOfPieces*/
			Piece * temp = pieces.at(i);
			pieces.erase(pieces.begin()+i);
			delete temp;
			break;
		}
			
	}

}


/*set and get methods for variable*/
Piece * Board::getPiece(const int * position) const{
	
	return board[position[0]][position[1]];

}

vector<Piece*> & Board::getPieces() {
	return pieces;
}
/*delete the original pawn and replace it with the piece that want to be promoted to. Currently just directly promote a pawn to a queen, more clever work need be done*/
void Board::doPromotion(Piece * p){
	for(int i=0;i<pieces.size();i++){
		if(pieces.at(i)== p){
			int * cord = new int[2];
			cord[0] = p->getPosition()[0];
			cord[1] = p->getPosition()[1];
			pieces.at(i)= new Queen(p->getColor(),cord);
			delete p;
		}
	}

}

Board::EnPassant * Board::getPassant() const{
	return passant;
}


/*since when call this function, the function increaseSteps() has not bee called so that a +1 is needed*/
void Board::setPassant(Piece * p){
	passant->p = p;
	passant->step = this->currentStep()+1;	
}

int Board::currentStep() const{
	return steps;
}

void Board::increaseSteps(){
	steps += 1;
}

/*test purpose*/
int main(){
	Board start(32,vector<Piece*>(0));
	start.initialize();
	start.display();
	HumanPlayer human(WHITE);
	while(1){
		
		human.humanPlay(start);
		}

}
