#ifndef TREE_H
#define TREE_H


#include "Info.h"
#include "Node.h"
#include "Heap.h"


class Tree
{
public:
	Tree(Info* pInfo);
	virtual ~Tree();
public:
	Node** GetLeaves();
	Node*  GetRoot();
private:
	void CreateLeaves(Info* pInfo,Heap<MIN_TYPE,Node>* pHeap);
	void CreateRoot(Info* pInfo,Heap<MIN_TYPE,Node>* pHeap);
private:
	void DestroyLeaves();
	void DestroyRoot();
private:
	Node** m_aLeaves;
	Node*  m_pRoot;
};


#endif
