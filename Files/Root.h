#ifndef ROOT_H
#define ROOT_H


class Root
{
	friend class Leaf;
protected:
	Root(Leaf* pChild0,Leaf* pChild1);
	virtual ~Root();
protected:
	Leaf* m_pChild0;
	Leaf* m_pChild1;
};


#endif
