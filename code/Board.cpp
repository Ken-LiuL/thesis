#include <string>
#include <cstdlib>
#include <iostream>
#include "Constants.h"
#include "Board.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"
#include "Pawn.h"
#include "Knight.h"
#include "Rook.h"

/*This class mainly relate with interaction between board display and pieceschanges under different moves*/

Board::Board(int n,Piece ** p=NULL){
	pieces = p; /* list that contains pointers of pieces on the board */
	numberOfPieces = n; /* number of pieces on the board */
	passant = new Board::EnPassant(); /* struct { Piece * and step} */
	steps = 0;/* record how many steps has been so far */
}

/*currently text mode display */
void Board::display(){
	using namespace std;
	int i,j;
	/*initialization of the board */
	int l  = 8;
        for(i=0;i<l;i++)
		for(j=0;j<l;j++)
			board[i][j] = NULL;
	for(i=0;i<numberOfPieces;i++){
		int * p = pieces[i]->getPosition();
		board[p[0]][p[1]] = pieces[i]; 

	}
	
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
	pieces  = new Piece*[32];
      	int i=0;
      	pieces[i++] = new Rook(WHITE,NULL);
     	pieces[i++] = new Knight(WHITE,NULL);
	pieces[i++] = new  Bishop(WHITE,NULL);
	pieces[i++] = new Queen(WHITE,NULL);
        pieces[i++] = new King(WHITE,NULL);
	pieces[i++] = new Bishop(WHITE,NULL);
     	pieces[i++] = new Knight(WHITE,NULL);
      	plieces[i++] = new Rook(WHITE,NULL);

        int j=0;
        for(;j<16;j++){
		if(j<8){
			Pawn * pawn = new Pawn(WHITE,NULL);
			pieces[i++] =pawn;
		}
		else{
			Pawn * pawn = new Pawn(BLACK,NULL);
			pieces[i++] = pawn;
			}
     	 }

      	pieces[i++] = new Rook(BLACK,NULL);
     	pieces[i++] =new Knight(BLACK,NULL);
	pieces[i++] = new Bishop(BLACK,NULL);
	pieces[i++] =  new Queen(BLACK,NULL);
	pieces[i++] =  new King(BLACK,NULL);
	pieces[i++] = new Bishop(BLACK,NULL);
     	pieces[i++] = new Knight(BLACK,NULL);
      	pieces[i] =  new Rook(BLACK,NULL);

	/*set the position of these piecess */
        for(i=0;i<16;i++){
	       	int * l =  new int[2];
	       	l[0] = i/8;
	       	l[1] = i%8;
	       	pieces[i]->setPosition(l);
	}
	for(i=48;i<64;i++){
		int * l = new int[2];
		l[0] = i/8;
		l[1] = i%8;
		pieces[i-32]->setPosition(l); 
	}

	
}

/*whether a borad sqaure is empty or occupied by a piece */
bool Board::occupied(int * position){
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
			if(p->makeMove(to,this)){
				/*if is a capture move,then list pieces and variable need to be updated */
				if(this->getPiece(to)!=NULL)
					this->capture(from,to);
				/*if just a move, then board need to be update*/
				else{
					board[to[0]][to[1]] = board[from[0]][from[1]];	
					board[from[0]][from[1]] = NULL;
				}
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
	for(int i=0;i<numberOfPieces;i++){
		if(pieces[i]==p){
			/*free memory,decremental variable numberOfPieces*/
			Piece * temp = pieces[i];
			int * tempPosition = temp->getPosition();
			pieces[i]=pieces[numberOfPieces-1];
			pieces[numberOfPieces-1]=NULL;
			numberOfPieces -= 1;
			/*update virable board*/
			board[to[0]][to[1]] = board[from[0]][from[1]];
			
			board[from[0]][from[1]] = NULL;
			
			delete tempPosition;
			delete temp;
			break;
		}
			
	}

}

/*set and get methods for variable*/
Piece * Board::getPiece(int * position){
	
	return board[position[0]][position[1]];

}

/*delete the original pawn and replace it with the piece that want to be promoted to. Currently just directly promote a pawn to a queen, more clever work need be done*/
void Board::doPromotion(Piece * p){
	for(int i=0;i<numberOfPieces;i++){
		if(pieces[i] == p){
			pieces[i] = new Queen(p->getColor(),p->getPosition());
			delete p;
		}
	}

}

Board::EnPassant * Board::getPassant(){
	return passant;
}

/*since when call this function, the function increaseSteps() has not bee called so that a +1 is needed*/
void Board::setPassant(Piece * p){
	passant->p = p;
	passant->step = this->currentStep()+1;	
}

int Board::currentStep(){
	return steps;
}

void Board::increaseSteps(){
	steps += 1;
}

/*test purpose*/
int main(){
	using namespace std;
	Board start =  Board(32);
	start.initialize();
	start.display();
	string command = "";
	while(1){
		getline(cin,command);
		if(command=="abort" || command=="quit"){
			exit(1);
		}
		int a,b,c,d;
		a = command[0]-'a';
		b = command[1]-'1';
		c = command[2] - 'a';
		d = command[3] - '1';
		
		int * from = new int[2];
		int * to = new int[2];
		from[0] = b;
		from[1] = a;
		to[0] = d;
		to[1] = c;
		if(start.makeMove(from,to)){
			start.display();
		}
		else
			cout << "error movement"<< endl;
		delete[] from;
		delete[] to;
	}

}
