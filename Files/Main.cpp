#include "Encoder.h"
#include "Decoder.h"
#include <string.h>


int SIZE_OF_SYMBOL = 1; // 1 or 2 or 3


int main(int argc,char* argv[])
{
	if (argc<4)
	{
		Encoder::Encode("SrcFile","ZipFile");
		Decoder::Decode("ZipFile","DstFile");
	}

	else if (!_stricmp(argv[1],"Encode"))
		Encoder::Encode(argv[2],argv[3]);

	else if (!_stricmp(argv[1],"Decode"))
		Decoder::Decode(argv[2],argv[3]);

	return 0;
}
