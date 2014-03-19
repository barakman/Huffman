#include "Leaf.h"
#include "Root.h"


Leaf::Leaf(int iSymbol,Root* pParent)
{
	m_iSymbol = iSymbol;
	m_pParent = pParent;
}


Leaf::~Leaf()
{
}
