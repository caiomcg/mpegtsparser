#include <iostream>
#include "Parser.h"

int main(int argc, char ** argv) {
	Parser* tsParser = new Parser("C:\\Users\\caiomcg\\Downloads\\video.ts");
	tsParser->readBytes();
	tsParser->readBytes();
	tsParser->readBytes();
	
	system("pause");
	delete tsParser;
	return 0;
}