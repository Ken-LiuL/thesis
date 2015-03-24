#include "Ep.h"
#include "../Constants.h"
#include <cmath>
#include <cstdlib>
#include <iostream>
#include "../ComputerPlayer.h"
	
/*top level class of the core algorithm, it provides interface to Player
  class, they are well modeled, the granity of this class is object Node
*/


Distribution Ep::descent(Node &n){
	if(n.isVisited()){
		Node* c = n.getChild();
		if(c!=NULL){
			c->sampleG();
			/*update message to c*/
			Ep::updateMessageFromParent(*c,n);
			/*continue to descent*/
			Distribution newMessage = descent(*c);
			/*update marginal of n*/
			Ep::updateMessageToParent(*c,n,newMessage);
		}
	}

	else{
		/*update message, include dividing roll out out of the distribution*/
		Node * parent  = n.getParent();
		Ep::updateMessageExceptRollOut(n,*parent);
		
		/*dealing with roll out*/
		/*assume this is returned by the roll out*/
	        
		int length = 0;
		int result = 0;
		Ep::doRollout(n,length,result);

		/*call function to calculated the approximate message*/
		Distribution rollOut = Ep::getMessageFromRollOut(n,length,result);	
		
		n.setDistribution(n.getDistribution()*rollOut);
		n.setVisited();
	}
	Distribution messageExceptP = n.getDistribution()/n.getMessageFromParent();

	return Distribution(messageExceptP.getMean(),messageExceptP.getVar()+1);

}

/*change as different board and computer player implementation*/
void Ep::doRollout(Node &n,int &l,int &r){
	Board b = n.getBoard();
	char color = n.getColor();
	ComputerPlayer p(color);
	char result;
	while(1){
		result = p.randomPlay(b);
		if(result != CONTINUE)
			break;
		p.setColor(p.getColor()==WHITE ? BLACK : WHITE);
	
		result = p.randomPlay(b);
		if(result != CONTINUE)
			break;
		p.setColor(p.getColor()==WHITE ? BLACK : WHITE);
	}
	l = p.step;
	r = result == 'X' ? 1 : -1;
}

Distribution Ep::getMessageFromRollOut(Node &boundary,const int length,const int result){
	Distribution prior = Distribution(boundary.getDistribution().getMean(),boundary.getDistribution().getVar()+length);
	double priorMean = prior.getMean();
	double priorVar = prior.getVar();

	double m,v,n,d,p,secondMoment;
	double meanSqaure = pow(priorMean,2);
	if(result>0){
		/*first moment*/
		n = Distribution(0,priorVar).pdf(priorMean);
		d = 1- prior.phi(0);
		/*seconde moment*/
		p = (1-(-priorMean*n)/d);
		
	}
	else{
		/*first moment*/
		n = -(Distribution(0,priorVar).pdf(priorMean));
		d =  prior.phi(0);
		/*second moment*/
		p  = (1-(priorMean*(-n)/d));

		}
	m = priorMean + priorVar*(n/d);
	secondMoment =  meanSqaure+ priorVar*p;
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

