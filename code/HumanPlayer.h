#pragma once
#include "Player.h"
class Board;
class HumanPlayer:public Player{
	public:
		HumanPlayer(char c);
		void play(Board &board);

};
