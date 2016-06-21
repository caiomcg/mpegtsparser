#include "Parser.h"

#include <iostream>

void printbincharpad(char c)
{
	for (int i = 7; i >= 0; --i)
	{
		putchar((c & (1 << i)) ? '1' : '0');
	}
	putchar('\n');
}

Parser::Parser(std::string videoFile) {
	fileName = videoFile;
	counter = 0;
	packetSize = 188;
	packet = new unsigned char[188]();
	
	reader.open(fileName, std::ifstream::in | std::ifstream::binary);
	if (!reader.is_open()) {
		throw "Could not open file";
	}
}

Parser::~Parser() {
	reader.close();
	delete packet;
}

void Parser::readBytes() {
	reader.read((char*)(&packet[0]), packetSize);
}
		
void Parser::processPatOnly() {

	while (true) {
		readBytes();
		if (packet[1] == 0x47 && (((packet[1] & 0x1F) << 8) | packet[2]) == 0) {
			Header head(0x47, ((packet[1] & 0x80) >> 7), ((packet[1] & 0x40) >> 6), ((packet[1] & 0x20) >> 5), (((packet[1] & 0x1F) << 8) | packet[2]), (packet[3] & 0xC0), ((packet[3] & 0x30) >> 4), (packet[3] & 0xF), counter++);
			PAT pat((unsigned int)packet[5], ((packet[6] & 0x80) >> 7), ((packet[6] & 0x03) | packet[7]), (packet[8] | packet[9]), ((unsigned int)((packet[10] & 0x3E) >> 1)), (packet[10] & 0x01), (unsigned int)(packet[11]), (unsigned int)(packet[12]));

			packetHeader.push_back(head);
			patTable.push_back(pat);
		}
		if (reader.eof())
			break;
	}
}
void Parser::process() {

}