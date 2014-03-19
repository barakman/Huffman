#include "FileWriter.h"


extern int SIZE_OF_SYMBOL;


FileWriter::FileWriter(char* pFileName,Coding eCoding,Info* pInfo)
{
	m_pFile = fopen(pFileName,"wb");

	switch (eCoding)
	{
		case ENCODING: InitSrcFile(pInfo); break;
		case DECODING: InitDstFile(pInfo); break;
	}

	m_iBitSeq    = 0;
	m_iBitSeqLen = 0;
}


FileWriter::~FileWriter()
{
	while (m_iBitSeqLen > 0)
		AddBit(0);
	fclose(m_pFile);
}


void FileWriter::AddBit(int iBit)
{
	m_iBitSeq |= iBit<<8;
	m_iBitSeq >>= 1;
	m_iBitSeqLen++;
	if (m_iBitSeqLen == 8)
	{
		fwrite(&m_iBitSeq,1,1,m_pFile);
		m_iBitSeqLen = 0;
	}
}


void FileWriter::AddSymbol(int iSymbol)
{
	fwrite(&iSymbol,SIZE_OF_SYMBOL,1,m_pFile);
}


void FileWriter::InitSrcFile(Info* pInfo)
{
	fwrite(&pInfo->m_iSymbolsRange,sizeof(int),1,m_pFile);
	fwrite(&pInfo->m_iNumOfSymbols,sizeof(int),1,m_pFile);

	for (int i=0; i<pInfo->m_iNumOfSymbols; i++)
	{
		AddSymbol(pInfo->m_aSymbolVector[i]);
		fwrite(pInfo->m_aSymCntVector+i,sizeof(int),1,m_pFile);
	}
}


void FileWriter::InitDstFile(Info* pInfo)
{
}
