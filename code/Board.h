#pragma once
#include <vector>
class Board{
	protected:
		int size;
		char board[10][10];
	public:
		Board(const int size);
		void initialize();
		void display();
		std::vector<Board*> nextBoardStates(const char color);
		void makeMove(const int i,const int j,const char color);
		bool checkWin(const char color);
};
