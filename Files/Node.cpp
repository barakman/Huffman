#include "Node.h"


Node::Node(int iSymbol,Node* pParent):Leaf(iSymbol,pParent),Root(0,0)
{
	m_iCount = 0;
}


Node::Node(Node* pChild0,Node* pChild1):Leaf(0,0),Root(pChild0,pChild1)
{
	m_iCount = *pChild0+*pChild1;
}


Node::~Node()
{
}


Node::operator int&()
{
	return m_iCount;
}


int Node::Symbol()
{
	return m_iSymbol;
}


Node* Node::Parent()
{
	return (Node*)m_pParent;
}


Node* Node::Child0()
{
	return (Node*)m_pChild0;
}


Node* Node::Child1()
{
	return (Node*)m_pChild1;
}
