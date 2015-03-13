#pragma once
#include "Player.h"
#include "algorithm/Node.h"
#include "algorithm/Distribution.h"
class Board;
class ComputerPlayer:public Player{
	private:
		char strategy;
		void randomPlay(Board &board);
		void algorithmPlay(Board &board);
	public:
		ComputerPlayer(const char color,const char stratege='R');
		void play(Board &board);
		Distribution descent(Node &n);
		

};
