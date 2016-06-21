#pragma once

class PAT {
private:
	unsigned int table_id;
	unsigned char section_syntax_indicator;
	unsigned char section_length;
	unsigned char transport_stream_id;
	unsigned int version_number;
	unsigned char current_next_indicator;
	unsigned int section_number;
	unsigned int last_section_number;
public:
	PAT();
	PAT(unsigned int table_id, unsigned char section_syntax_indicator, unsigned char section_length, unsigned char transport_stream_id, unsigned int version_number, unsigned char current_next_indicator, unsigned int section_number, unsigned int last_section_number);
	~PAT();

	unsigned int getTableId();
	unsigned char getSectionSyntax();
	unsigned char getSectionLength();
	unsigned char getTransportStreamId();
	unsigned int getVersionNumber();
	unsigned char getCurrentNextIndicator();
	unsigned int getSectionNumber();
	unsigned int getLastSectionNumber();
};

