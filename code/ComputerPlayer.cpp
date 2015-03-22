#include "ComputerPlayer.h"
#include "Board.h"
#include <vector>
#include <iostream>
#include <ctime>
#include <cstdlib>

ComputerPlayer::ComputerPlayer(const char color){
	this->color = color;
}

void ComputerPlayer::play(Board &board){
	std::vector<Board*> states=board.nextBoardStates(this->color);	
	if(states.empty()){
		std::cout << " draw " << std::endl;	
		exit(0);
	}
	else{
		srand(time(NULL));
		board = *states[rand() % (states.size())];
		if(board.checkWin(this->color)){
			board.display();
			std::cout << this->color << " win" << std::endl;
			exit(0);
		}
	}
	for(int i=0;i<states.size();i++){
		delete states[i];
	}

}
