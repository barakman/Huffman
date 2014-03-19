#ifndef LEAF_H
#define LEAF_H


class Leaf
{
	friend class Root;
protected:
	Leaf(int iSymbol,Root* pParent);
	virtual ~Leaf();
protected:
	int   m_iSymbol;
	Root* m_pParent;
};


#endif
