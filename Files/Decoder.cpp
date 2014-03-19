#include "Decoder.h"


Decoder::Decoder()
{
}


Decoder::~Decoder()
{
}


void Decoder::Decode(char* pSrcFile,char* pDstFile)
{
	Info cInfo;

	FileReader cFileReader(pSrcFile,DECODING,&cInfo);
	FileWriter cFileWriter(pDstFile,DECODING,&cInfo);

	Tree cTree(&cInfo);
	Node* pRoot = cTree.GetRoot();

	for (int i=0; i<cInfo.m_iSymbolsCount; i++)
	{
		int iSymbol = DecodeSymbol(pRoot,&cFileReader);
		cFileWriter.AddSymbol(iSymbol);
	}
}


int Decoder::DecodeSymbol(Node* pNode,FileReader* pFileReader)
{
	Node* pChild0 = pNode->Child0();
	Node* pChild1 = pNode->Child1();
	if (pChild0 && pChild1)
	{
		int iBit = pFileReader->GetBit();
		return DecodeSymbol(iBit==0? pChild0:pChild1,pFileReader);
	}
	return pNode->Symbol();
}
