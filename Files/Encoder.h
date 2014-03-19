#ifndef ENCODER_H
#define ENCODER_H


#include "Tree.h"
#include "FileReader.h"
#include "FileWriter.h"


class Encoder
{
protected:
	Encoder();
	virtual ~Encoder();
public:
	static void Encode(char* pSrcFile,char* pDstFile);
private:
	static void EncodeSymbol(Node* pNode,FileWriter* pFileWriter);
};


#endif
