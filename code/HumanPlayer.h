#pragma once
class Board;
class HumanPlayer{
	private:
		char color;
		bool checkmated;
		
	public:
		HumanPlayer(char c);
		void humanPlay(Board &board);
		bool beCheckmated(Board &board);

};
