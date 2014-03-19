#include "Info.h"


Info::Info()
{
	m_iSymbolsCount = 0;
	m_iSymbolsRange = 0;
	m_iNumOfSymbols = 0;
	m_aSymbolVector = 0;
	m_aSymCntVector = 0;
}


Info::~Info()
{
	if (m_aSymbolVector)
		delete[] m_aSymbolVector;
	if (m_aSymCntVector)
		delete[] m_aSymCntVector;
}
