#include "Root.h"
#include "Leaf.h"


Root::Root(Leaf* pChild0,Leaf* pChild1)
{
	m_pChild0 = pChild0;
	m_pChild1 = pChild1;
	if (m_pChild0)
		m_pChild0->m_pParent = this;
	if (m_pChild1)
		m_pChild1->m_pParent = this;
}


Root::~Root()
{
}
