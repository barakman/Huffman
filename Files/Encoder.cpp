#include "Encoder.h"


Encoder::Encoder()
{
}


Encoder::~Encoder()
{
}


void Encoder::Encode(char* pSrcFile,char* pDstFile)
{
	Info cInfo;

	FileReader cFileReader(pSrcFile,ENCODING,&cInfo);
	FileWriter cFileWriter(pDstFile,ENCODING,&cInfo);

	Tree cTree(&cInfo);
	Node** aLeaves = cTree.GetLeaves();

	for (int i=0; i<cInfo.m_iSymbolsCount; i++)
	{
		int iSymbol = cFileReader.GetSymbol();
		EncodeSymbol(aLeaves[iSymbol],&cFileWriter);
	}
}


void Encoder::EncodeSymbol(Node* pNode,FileWriter* pFileWriter)
{
	Node* pParent = pNode->Parent();
	if (pParent)
	{
		int iBit = (pNode==pParent->Child0()? 0:1);
		EncodeSymbol(pParent,pFileWriter);
		pFileWriter->AddBit(iBit);
	}
}
