#pragma once
class Board;
class Player{
	protected:
		char color;
	public:
		Player(const char color);
		virtual void play(Board &board)=0;
		char getColor();

};
