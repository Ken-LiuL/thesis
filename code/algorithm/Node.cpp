#include "Node.h"
#include "../Constants.h"
#include "../Board.h"
#include <vector>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <random>
using namespace std;

/*This class provide interface to top level class Ep to do calculation , if the data structure of Board has changed, then function getChild needs rewrite*/

Node::Node(Board &b,Distribution &d,const char c,const double g,const double v){
	board = b;
	gDis = d;
	gValue = g;
	vValue = v;
	visited= FALSE;
	color = c;
	parent = NULL;
	
}

Node::~Node(){
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

	if(children.empty())
		return (Node *)NULL;
	else{
		std::mt19937 rng;
                rng.seed(std::random_device()());
                std::uniform_int_distribution<std::mt19937::result_type> randomChild(0,children.size()-1);

		return children[randomChild(rng)];
	}
}

void Node::setGDis(const Distribution &dis){
	gDis = dis;
}

void Node::setVDis(const Distribution &dis){
	vDis = dis;
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
Distribution &Node::getGDis(){
	return gDis;
}
Distribution &Node::getVDis(){
	return vDis;
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

Board &Node::getBoard() {
	return board;
}

char Node::getColor(){
	return color;
}

std::vector<Node*> Node::getChildren(){
	return children;
}
