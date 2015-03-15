#include "Ep.h"
#include <cmath>
	
/*top level class of the core algorithm, it provides interface to Player
  class, they are well modeled, the granity of this class is object Node
*/


Distribution Ep::descent(Node &n){
	if(n.isVisited()){
		Node* c = n.getChild();
		c->sampleG();
		/*update message to c*/
		Ep::updateMessageFromParent(*c,n);
		/*continue to descent*/
		Distribution newMessage = descent(*c);
		/*update marginal of n*/
		Ep::updateMessageToParent(*c,n,newMessage);
	}

	else{
		/*update message, include dividing roll out out of the distribution*/
		Node * parent  = n.getParent();
		Ep::updateMessageExceptRollOut(n,*parent);
		
		/*dealing with roll out*/
		/*assume this is returned by the roll out*/
	        int length = 3;
		int result = 1;
		/*call function to calculated the approximate message*/
		Distribution rollOut = this->getMessageFromRollOut(length,result);	
		
		n.setDistribution(n.getDistribution()*rollOut);
		n.setVisited();
	}

}


Distribution Ep:getMessageFromRollOut(const Node &boundary,const int length,const int result){
	Distribution prior = Distribution(boundary.getMean(),boundary.getVar()+length);
	double m,v,n,d,p,secondMoment;
	double meanSqaure = pow(this->mean,2);
	if(result>0){
		/*first moment*/
		n = Distribution(0,this->var).pdf(this->mean);
		d = 1- this->phi(0);
		/*seconde moment*/
		p = (1-(-this->mean*n)/d);
		
	}
	else{
		/*first moment*/
		n = -(Distribution(0,this->var).pdf(this->mean));
		d =  this->phi(0);
		/*second moment*/
		p  = (1-(this->mean*(-n)/d));

		}
	m = this->mean + this->var*(n/d);
	secondMoment =  meanSqaure+ this->var*p;
	/*variance*/
	v = secondMoment - pow(m,2);
	
	return Distribution(m,v+length);
}

void Ep::updateMessageFromParent(Node &child,Node &parent){
	child.setDistribution(child.getDistribution()/child.getMessageFromParent());
	Distribution messageExceptC = parent.getDistribution()/child.getMessageToParent();
	Distribution messageIntegral = Distribution(messageExceptC.getMean(),messageExceptC.getVar()+1);
	child.setMessageFromParent(messageIntegral);
	child.setDistribution(child.getDistribution()*child.getMessageFromParent());
}

void Ep::updateMessageExceptRollOut(Node &child,Node &parent){
	Distribution newParent = parent.getDistribution()/parent.getRollOut();
	child.setDistribution(child.getDistribution()/child.getMessageFromParent());
	Distribution messageExceptC = newParent/child.getMessageToParent();
	Distribution messageIntegral = Distribution(messageExceptC.getMean(),messageExceptC.getVar()+1);
	child.setDistribution(child.getDistribution()*messageIntegral);
	child.setMessageFromParent(messageIntegral);
}

void Ep::updateMessageToParent(Node &child,Node &parent,Distribution &message){
	
	parent.setDistribution(parent.getDistribution()/child.getMessageToParent()*message);
	child.setMessageToParent(message);

}

