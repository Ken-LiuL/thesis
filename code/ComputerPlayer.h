#pragma once
#include "Player.h"
class Board;
class ComputerPlayer:public Player{
	private:
		char strategy;
	public:
		ComputerPlayer(char color,char stratege='R');
		void play(Board &board);
		

};
