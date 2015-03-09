#pragma once

class Coordinate{
	private:
		int rank;
		int col;

	public:
		bool isInBoard() const;
		Coordinate(int x, int y);
		Coordinate();
		int operator[](int i) const;
		int getRank() const;
		int getCol() const;		
		void update(const Coordinate &c);
		int & operator[](int i);
		void setRank(const int x);
		void setCol(const int y);
		bool operator==(Coordinate &cord);

};
