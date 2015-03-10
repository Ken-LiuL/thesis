#pragma once
class Board;
class Player{
	private:
		char color;
	public:
		Player(const char color);
		virtual void play(Board &board)=0;
		bool amICheckmated(Board &board);
		char getColor();

};
