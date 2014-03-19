#ifndef FILE_READER_H
#define FILE_READER_H


#include "Info.h"
#include <stdio.h>


class FileReader
{
public:
	FileReader(char* pFileName,Coding eCoding,Info* pInfo);
	virtual ~FileReader();
public:
	int GetBit();
	int GetSymbol();
private:
	void InitSrcFile(Info* pInfo);
	void InitDstFile(Info* pInfo);
private:
	FILE* m_pFile;
	int   m_iBitSeq;
	int   m_iBitSeqLen;
};


#endif
