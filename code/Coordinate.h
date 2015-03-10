#pragma once

class Coordinate{
	private:
		int rank;
		int col;

	public:
		bool isInBoard() const;
		Coordinate(const int x, const int y);
		Coordinate();
		int operator[](const int i) const;
		int getRank() const;
		int getCol() const;		
		void update(const Coordinate &c);
		int & operator[](const int i);
		void setRank(const int x);
		void setCol(const int y);
		bool operator==(const Coordinate cord) const;

};
