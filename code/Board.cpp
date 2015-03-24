#include "Board.h"
#include "ComputerPlayer.h"
#include <iostream>
#include "Constants.h"
#include <vector>
using namespace std;

Board::Board(int size){
	this->size = size;
	this->initialize();
}

Board::Board(){
	;
}

Board::Board(Board &b){
	size = b.size;
	for(int i=0;i<size;i++)
		for(int j=0;j<size;j++)
			board[i][j] = b.board[i][j];
}

void Board::display(){
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++)
			cout << board[i][j] << ' ';
		cout << endl;
	}

	cout << endl << endl;
}


void Board::initialize(){
	for(int i=0;i<size;i++)
		for(int j=0;j<size;j++)
			board[i][j] = '_';
	
}

std::vector<Board*> Board::nextBoardStates(const char color){
	std::vector<Board*> states(0);
	for(int i=0;i<size;i++)
		for(int j=0;j<size;j++){
			if(board[i][j]=='_'){
				Board * s = new Board(size);
				*s = *this;
				s->makeMove(i,j,color);
				states.push_back(s);
			}
		}

	return states;
}

bool Board::checkWin(const char color){
	char c=color;
	bool win;
	int i,j;
	/*vertical*/
	for(j=0;j<size;j++){
		win = 1;
		for(i=0;i<size;i++){
			if(board[i][j] != c){	
				win = 0;
				break;
			}		
		}
		if(win)
			return win;
	}
	/*horizontal*/
	for(i=0;i<size;i++){
		win = 1;
		for(j=0;j<size;j++){
			if(board[i][j] != c){
				win =0;
				break;
			}
			
		}
		if(win)
			return win;
	}


	/*diagonal*/
	win = 1;
	for(i=0,j=0;i<size;i++,j++){
		if(board[i][j] != c){
			win = 0;
			break;
		}
	}
	if(win)
		return win;

	win = 1;
	for(i = size-1,j=size-1;i>-1;i--,j--){
		if(board[i][j]!=c){
			win = 0;
			break;
		}
		
	}
	return win;
}

void Board::makeMove(const int i,const int j, const char color){
	board[i][j] = color;

}

int main(){
	int times=100;
	int winTimes =0;
	while(times-->0){
		Board start(3);
		start.display();
	
		ComputerPlayer player1(WHITE);
		ComputerPlayer player2(BLACK);

		char result;
	
		while(1){
			result = player1.algorithmPlay(start);
			start.display();
			if(result != ' '){
				std::cout << result << " win" <<std::endl;
				break;
			}
			result = player2.randomPlay(start);
			start.display();
			if(result != ' '){
				std::cout << result << " win" << std::endl;
				break;
			}

		}
		if(result == WHITE)
			winTimes ++;
	}
	std::cout << winTimes << std::endl;
}
