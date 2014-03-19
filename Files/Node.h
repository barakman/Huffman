#ifndef NODE_H
#define NODE_H


#include "Leaf.h"
#include "Root.h"


class Node : public Leaf, public Root
{
public:
	Node(int iSymbol,Node* pParent=0);
	Node(Node* pChild0=0,Node* pChild1=0);
	virtual ~Node();
	operator int&();
public:
	int   Symbol();
	Node* Parent();
	Node* Child0();
	Node* Child1();
private:
	int m_iCount;
};


#endif
