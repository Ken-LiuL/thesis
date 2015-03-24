#pragma once
class Board;
class ComputerPlayer{
	protected:
		char color;
	public:
		int step;
		char randomPlay(Board &b);
		ComputerPlayer(const char color);
		char algorithmPlay(Board &b);
		void setColor(const char color);
		char getColor();
};
