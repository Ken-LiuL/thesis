#pragma once
#include "../Board.h"
#include "Distribution.h"

class Node{
	protected:
		Board board;
		Distribution dis;
		double gValue;
		double vValue;
		bool visited;
		char color;
		std::vector<Node*> children;
		Node * parent;	
		Distribution messageToParent;
		Distribution messageFromParent;
		Distribution rollOut;
	public:
		Node(Board &b,Distribution &d,const char color ,const double gValue=0.0,const double vValue=0.0);
		~Node();
		double getG() const;
		double getV() const;
		Distribution &getDistribution() ;
		Distribution &getMessageToParent() ;
		Distribution &getMessageFromParent() ;
		Distribution &getRollOut() ;
		const Board &getBoard() const;
		Node * getParent() ;
		Node * getChild() ;	

		void setDistribution(const Distribution &dis);
		void setParent(Node * n);
		void setMessageToParent(const Distribution &dis);
		void setMessageFromParent(const Distribution &dis);
		void setVisited();

		bool isVisited() const;
		void sampleG();
	;	

};
