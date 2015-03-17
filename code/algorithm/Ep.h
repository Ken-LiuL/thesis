#pragma once
#include "Distribution.h"
#include "Node.h"

class Ep{
	public:
		static void updateMessageFromParent(Node &child,Node &parent);
		static void updateMessageToParent(Node &child,Node &parent,Distribution &message);
		static void updateMessageExceptRollOut(Node &child,Node &parent);
		static Distribution descent(Node &n);
		
		static Distribution getMessageFromRollOut(Node &b,const int len,const int result);
};
