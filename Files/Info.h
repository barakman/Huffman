#ifndef INFO_H
#define INFO_H


typedef enum {ENCODING,DECODING} Coding;


class Info
{
public:
	Info();
	virtual ~Info();
public:
	int  m_iSymbolsCount;
	int  m_iSymbolsRange;
	int  m_iNumOfSymbols;
	int* m_aSymbolVector;
	int* m_aSymCntVector;
};


#endif
