#include "Node.h"
#include "../Constants.h"
#include "../piece.h"
#include "../Board.h"
#include "../Coordinate.h"
#include "../ComputerPlayer.h"
#include <vector>
#include <iostream>
using namespace std;

Node::Node(Board &b,Distribution &d,const char c,const double g,const double v){
	board = b;
	dis = d;
	gValue = g;
	vValue = v;
	visited= FALSE;
	color = c;

}


double Node::getG() const{
	return gValue;
}

void Node::setVisited(){
	
	visited = TRUE;

}
void Node::sampleG() {
	gValue = dis.getSample();
}

double Node::getV() const{
	return vValue;
}

Node * Node::getChild(){
	/*generate children*/
	if(children.empty()){
		vector<Piece*> pieces=board.getPieces();
		for(vector<Piece*>::iterator it=pieces.begin();it<pieces.end();it++){
			if((*it)->getColor() != this->color)
				continue;

			vector<Coordinate> moves  =  (*it)->legalMoves(board);
			for(vector<Coordinate>::iterator iit=moves.begin();iit<moves.end();iit++){
				Board boardBackup = board;
				if(boardBackup.makeMove((*it)->getPosition(),(*iit)) && !ComputerPlayer(this->color).amICheckmated(boardBackup)){
					Distribution prior(gValue,1);
					Node * cc = new Node(boardBackup,prior,this->color == BLACK ? BLACK : WHITE);
					cc->setParent(this);
					children.push_back(cc);


				}
			}

		}
	
	}

	Node * child = children.back();
	std::cout << children.size() << std::endl;
	children.pop_back();
	return child;
}

void Node::setDistribution(const Distribution &dis){
	this->dis = dis;
}

Distribution Node::getDistribution(){
	return this->dis;
}

Distribution Node::getMessageFromParent(){
	return messageFromParent;
}
Distribution Node::getMessageToParent(){

	return messageToParent;
}
Distribution Node::getRollOut(){
	return rollOut;
}

Node * Node::getParent(){
	return parent;
}

void Node::setParent(Node * n){
	parent = n;
}
void Node::setMessageToParent(const Distribution &dis){

	messageToParent =  dis;
}

void Node::setMessageFromParent(const Distribution &dis){
	messageFromParent = dis;
}
bool Node::isVisited() const{
	return visited;
}

const Board &Node::getBoard() const{
	return board;
}


