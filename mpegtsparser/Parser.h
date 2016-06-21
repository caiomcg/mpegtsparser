#pragma once

#include <vector>
#include <fstream>

#include "Header.h"
#include "PAT.h"
#include "PMT.h"

class Parser {
private:
	std::string fileName;
	std::ifstream reader;

	std::vector<PAT> patTable;
	std::vector<PMT> pmtTable;
	std::vector<Header> packetHeader;

	short packetSize;
	unsigned char* packet;
	unsigned int counter;
	
	void readBytes();

public:
	Parser(std::string videoFile);
	~Parser();

	void processPatOnly();
	void process();
};