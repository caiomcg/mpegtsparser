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
	
	if (packet[0] != 0x47)
		readBytes();
	else {
		std::cout << "sync_byte = " << "0x47" << std::endl;
		std::cout << "transport_error_indicator = " << ((packet[1] & 0x80) >> 7) << std::endl;
		std::cout << "payload_unit_start_indicator = " << ((packet[1] & 0x40) >> 6) << std::endl;
		std::cout << "transport_priority = " << ((packet[1] & 0x20) >> 5) << std::endl;
		std::cout << "PID = " << (((packet[1] & 0x1F) << 8) | packet[2]) << std::endl;
		std::cout << "transport_scrambling_control = " << (packet[3] & 0xC0) << std::endl;
		switch ((packet[3] >> 6)){
		case 0x00:
			std::cout << "    Not Scrambled" << std::endl;
			break;
		case 0x01:
			std::cout << "    Reserved for future use" << std::endl;
			break;
		case 0x02:
			std::cout << "    Scrambled with even key" << std::endl;
			break;  
		case 0x03:
			std::cout << "    Scrambled with odd key" << std::endl;
			break;
		}
		std::cout << "adaptation_field_control = " << ((packet[3] & 0x30) >> 4) << std::endl;
		std::cout << "continuity_counter = " << (packet[3] & 0xF) << std::endl;
		int a;
		std::cin >> a;

	}
}