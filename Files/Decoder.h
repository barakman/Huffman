#ifndef DECODER_H
#define DECODER_H


#include "Tree.h"
#include "FileReader.h"
#include "FileWriter.h"


class Decoder
{
protected:
	Decoder();
	virtual ~Decoder();
public:
	static void Decode(char* pSrcFile,char* pDstFile);
private:
	static int  DecodeSymbol(Node* pNode,FileReader* pFileReader);
};


#endif
