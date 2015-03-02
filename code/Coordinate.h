#pragma once

class Coordinate{
	private:
		int rank;
		int col;

	public:
		bool isInBoard() const;
		Coordinate(int x, int y);
		Coordinate();
		int getRank() const;
		int getCol() const;		
		void update(const Coordinate &c);
		void setRank(const int x);
		void setCol(const int y);

};
