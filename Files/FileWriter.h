#ifndef FILE_WRITER_H
#define FILE_WRITER_H


#include "Info.h"
#include <stdio.h>


class FileWriter
{
public:
	FileWriter(char* pFileName,Coding eCoding,Info* pInfo);
	virtual ~FileWriter();
public:
	void AddBit(int iBit);
	void AddSymbol(int iSymbol);
private:
	void InitSrcFile(Info* pInfo);
	void InitDstFile(Info* pInfo);
private:
	FILE* m_pFile;
	int   m_iBitSeq;
	int   m_iBitSeqLen;
};


#endif
