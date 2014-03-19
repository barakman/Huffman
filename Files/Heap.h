#ifndef HEAP_H
#define HEAP_H


//////////////////////////////////////////////////////////////////////////
//                                                                      //
// CLASS NAME:  Heap                                                    //
//                                                                      //
// DESCRIPTION: -Stores up to N items of type T.                        //
//              -Allows adding an item or extracting the best item.     //
//              -Supported operations are accomplished at O(log(n)),    //
//               where n is the current number of items in the heap.    //
//                                                                      //
// REMARKS:     1) T is determined at declaration.                      //
//              2) N is determined at initialization.                   //
//              3) The meaning of "best", either minimal or maximal,    //
//                 is determined at declaration.                        //
//                 In order to support Heap<MIN,T> and Heap<MAX,T>,     //
//                 one of the following options must be viable:         //
//                 1. bool operator<(T,T) and bool operator>(T,T).      //
//                 2. bool T::operator<(T) and bool T::operator>(T).    //
//                 3. T::operator P(), where P is a type, for which,    //
//                    one of the above options is viable.               //
//                                                                      //
// AUTHOR:      Barakman (barakman@yahoo.com)                           //
//                                                                      //
//////////////////////////////////////////////////////////////////////////


#define MIN_TYPE  0
#define MAX_TYPE ~0


template<int TYPE,typename ITEM>
class Heap
{
public:
	Heap(int iMaxNumOfItems);
	virtual ~Heap();
public:
	bool AddItem(ITEM*  pItem);
	bool GetBest(ITEM** pItem);
protected:
	int  BestOfTwo(int i,int j);
	void SwapItems(int i,int j);
protected:
	ITEM** m_aItems;
	int    m_iMaxNumOfItems;
	int    m_iCurrNumOfItems;
};


template<int TYPE,typename ITEM>
Heap<TYPE,ITEM>::Heap(int iMaxNumOfItems)
{
	m_iCurrNumOfItems = 0;
	m_iMaxNumOfItems = iMaxNumOfItems;
	m_aItems = new ITEM*[m_iMaxNumOfItems];
	if (!m_aItems)
		throw "Insufficient Memory";
}


template<int TYPE,typename ITEM>
Heap<TYPE,ITEM>::~Heap()
{
	delete[] m_aItems;
}


template<int TYPE,typename ITEM>
bool Heap<TYPE,ITEM>::AddItem(ITEM* pItem)
{
	if (m_iCurrNumOfItems == m_iMaxNumOfItems)
		return false;

	m_aItems[m_iCurrNumOfItems] = pItem;

	for (int i=m_iCurrNumOfItems,j=(i+1)/2-1; j>=0; i=j,j=(i+1)/2-1)
	{
		if (BestOfTwo(i,j) == i)
			SwapItems(i,j);
		else
			break;
	}

	m_iCurrNumOfItems++;

	return true;
}


template<int TYPE,typename ITEM>
bool Heap<TYPE,ITEM>::GetBest(ITEM** pItem)
{
	if (m_iCurrNumOfItems == 0)
		return false;

	m_iCurrNumOfItems--;

	*pItem = m_aItems[0];
	m_aItems[0] = m_aItems[m_iCurrNumOfItems];

	for (int i=0,j=(i+1)*2-1; j<m_iCurrNumOfItems; i=j,j=(i+1)*2-1)
	{
		if (j+1 < m_iCurrNumOfItems)
			j = BestOfTwo(j,j+1);
		if (BestOfTwo(i,j) == j)
			SwapItems(i,j);
		else
			break;
	}

	return true;
}


template<int TYPE,typename ITEM>
int Heap<TYPE,ITEM>::BestOfTwo(int i,int j)
{
	switch (TYPE)
	{
		case MIN_TYPE: return *m_aItems[i]<*m_aItems[j]? i:j;
		case MAX_TYPE: return *m_aItems[i]>*m_aItems[j]? i:j;
	}
	throw "Illegal Type";
}


template<int TYPE,typename ITEM>
void Heap<TYPE,ITEM>::SwapItems(int i,int j)
{
	ITEM* pItem = m_aItems[i];
	m_aItems[i] = m_aItems[j];
	m_aItems[j] = pItem;
}


#endif
