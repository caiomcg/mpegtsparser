#include <iostream>
#include "Parser.h"

int main(int argc, char** argv) {
	Parser* tsParser = new Parser("C:\\Users\\caiomcg\\Downloads\\video.ts");
	system("pause");
	delete tsParser;
	return 0;
}