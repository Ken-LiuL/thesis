#pragma once
class Board;
class ComputerPlayer{
	protected:
		char color;
	public:
		void play(Board &b);
		ComputerPlayer(const char color);
};
