#include "Tree.h"


Tree::Tree(Info* pInfo)
{
	Heap<MIN_TYPE,Node>* pHeap = new Heap<MIN_TYPE,Node>(pInfo->m_iNumOfSymbols);
	CreateLeaves(pInfo,pHeap);
	CreateRoot(pInfo,pHeap);
	delete pHeap;
}


Tree::~Tree()
{
	DestroyLeaves();
	DestroyRoot();
}


Node** Tree::GetLeaves()
{
	return m_aLeaves;
}


Node* Tree::GetRoot()
{
	return m_pRoot;
}


void Tree::CreateLeaves(Info* pInfo,Heap<MIN_TYPE,Node>* pHeap)
{
	int* aSymbolVector = pInfo->m_aSymbolVector;
	int* aSymCntVector = pInfo->m_aSymCntVector;

	m_aLeaves = new Node*[pInfo->m_iSymbolsRange];
	for (int i=0; i<pInfo->m_iNumOfSymbols; i++)
	{
		m_aLeaves[aSymbolVector[i]] = new Node(aSymbolVector[i]);
		(int&)(*m_aLeaves[aSymbolVector[i]]) = aSymCntVector[i];
		pHeap->AddItem(m_aLeaves[aSymbolVector[i]]);
	}
}


void Tree::CreateRoot(Info* pInfo,Heap<MIN_TYPE,Node>* pHeap)
{
	Node* pChild0;
	Node* pChild1;

	for (int i=0; i<pInfo->m_iNumOfSymbols-1; i++)
	{
		pHeap->GetBest(&pChild0);
		pHeap->GetBest(&pChild1);
		pHeap->AddItem(new Node(pChild0,pChild1));
	}
	pHeap->GetBest(&m_pRoot);
}


void Tree::DestroyLeaves()
{
	delete[] m_aLeaves;
}


void Tree::DestroyRoot()
{
	Node* pParent;
	if (m_pRoot)
	{
		pParent = m_pRoot;
		m_pRoot = pParent->Child0();
		DestroyRoot();
		m_pRoot = pParent->Child1();
		DestroyRoot();
		delete pParent;
	}
}
