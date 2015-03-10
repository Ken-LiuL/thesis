#pragma once
#include "Player.h"
class Board;
class ComputerPlayer:public Player{
	private:
		char strategy;
	public:
		ComputerPlayer(const char color,const char stratege='R');
		void play(Board &board);
		

};
