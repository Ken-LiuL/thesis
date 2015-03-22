#include "Node.h"
#include "../Constants.h"
#include "../Board.h"
#include <vector>
#include <iostream>
using namespace std;

/*This class provide interface to top level class Ep to do calculation , if the data structure of Board has changed, then function getChild needs rewrite*/

Node::Node(Board &b,Distribution &d,const char c,const double g,const double v){
	board = b;
	dis = d;
	gValue = g;
	vValue = v;
	visited= FALSE;
	color = c;
	parent = NULL;
}

Node::~Node(){
 	delete parent;
	for(std::vector<Node*>::iterator it=children.begin();it<children.end();it++)
		delete (*it);
}

double Node::getG() const{
	return gValue;
}

void Node::setVisited(){
	
	visited = TRUE;

}
void Node::sampleG() {
	if(this->parent == NULL)
		gValue = dis.getSample();
	else
		gValue = Distribution(this->parent->getG(),1).getSample();
}

double Node::getV() const{
	return vValue;
}

Node * Node::getChild()  {
	/*generate children*/
	if(children.empty()){
		vector<Board*>	states = this->board.nextBoardStates(this->color);
		for(vector<Board*>::iterator it=states.begin();it<states.end();it++){
			Distribution prior(0,0);
			Node * cc = new Node((**it),prior,this->color == BLACK ? WHITE:BLACK);
			cc->setParent(this);
			children.push_back(cc);
			delete (*it);

		}

	}

	
	return children.back();
}

void Node::setDistribution(const Distribution &dis){
	this->dis = dis;
}

Distribution &Node::getDistribution() {
	return this->dis;
}

Distribution &Node::getMessageFromParent() {
	return messageFromParent;
}
Distribution &Node::getMessageToParent() {

	return messageToParent;
}
Distribution &Node::getRollOut() {
	return rollOut;
}

Distribution &Node::getDelta(){
	return delta;
}

Node * Node::getParent() {
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


