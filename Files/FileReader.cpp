#include "FileReader.h"


extern int SIZE_OF_SYMBOL;


FileReader::FileReader(char* pFileName,Coding eCoding,Info* pInfo)
{
	m_pFile = fopen(pFileName,"rb");

	switch (eCoding)
	{
		case ENCODING: InitSrcFile(pInfo); break;
		case DECODING: InitDstFile(pInfo); break;
	}

	m_iBitSeq    = 0;
	m_iBitSeqLen = 0;
}


FileReader::~FileReader()
{
	fclose(m_pFile);
}


int FileReader::GetBit()
{
	if (m_iBitSeqLen == 0)
	{
		fread(&m_iBitSeq,1,1,m_pFile);
		m_iBitSeqLen = 8;
	}
	int iBit = m_iBitSeq&1;
	m_iBitSeq >>= 1;
	m_iBitSeqLen--;
	return iBit;
}


int FileReader::GetSymbol()
{
	int iSymbol = 0;
	fread(&iSymbol,SIZE_OF_SYMBOL,1,m_pFile);
	return iSymbol;
}


void FileReader::InitSrcFile(Info* pInfo)
{
	fseek(m_pFile,0,SEEK_END);
	pInfo->m_iSymbolsCount = ftell(m_pFile)/SIZE_OF_SYMBOL;
	fseek(m_pFile,0,SEEK_SET);

	int iHistLen = 1<<(SIZE_OF_SYMBOL*8);
	int* aHistogram = new int[iHistLen];
	for (int i=0; i<iHistLen; i++)
		aHistogram[i] = 0;

	pInfo->m_iSymbolsRange = 0;
	pInfo->m_iNumOfSymbols = 0;
	for (int i=0; i<pInfo->m_iSymbolsCount; i++)
	{
		int iSymbol = GetSymbol();
		if (pInfo->m_iSymbolsRange < iSymbol+1)
			pInfo->m_iSymbolsRange = iSymbol+1;
		if (aHistogram[iSymbol]++ == 0)
			pInfo->m_iNumOfSymbols++;
	}
	fseek(m_pFile,0,SEEK_SET);

	int iSymbolNum = 0;
	pInfo->m_aSymbolVector = new int[pInfo->m_iNumOfSymbols];
	pInfo->m_aSymCntVector = new int[pInfo->m_iNumOfSymbols];
	for (int i=0; i<pInfo->m_iSymbolsRange; i++)
	{
		if (aHistogram[i] > 0)
		{
			pInfo->m_aSymbolVector[iSymbolNum] = i;
			pInfo->m_aSymCntVector[iSymbolNum] = aHistogram[i];
			iSymbolNum++;
		}
	}

	delete[] aHistogram;
}


void FileReader::InitDstFile(Info* pInfo)
{
	pInfo->m_iSymbolsCount = 0;
	fread(&pInfo->m_iSymbolsRange,sizeof(int),1,m_pFile);
	fread(&pInfo->m_iNumOfSymbols,sizeof(int),1,m_pFile);
	pInfo->m_aSymbolVector = new int[pInfo->m_iNumOfSymbols];
	pInfo->m_aSymCntVector = new int[pInfo->m_iNumOfSymbols];

	for (int i=0; i<pInfo->m_iNumOfSymbols; i++)
	{
		pInfo->m_aSymbolVector[i] = GetSymbol();
		fread(pInfo->m_aSymCntVector+i,sizeof(int),1,m_pFile);
		pInfo->m_iSymbolsCount += pInfo->m_aSymCntVector[i];
	}
}
