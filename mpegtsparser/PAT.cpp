#include "PAT.h"

PAT::PAT() {}

PAT::PAT(unsigned int table_id, unsigned char section_syntax_indicator, unsigned char section_length, unsigned char transport_stream_id, unsigned int version_number, unsigned char current_next_indicator, unsigned int section_number, unsigned int last_section_number) {
	this->table_id = table_id;
	this->section_syntax_indicator = section_syntax_indicator;
	this->section_length = section_length;
	this->transport_stream_id = transport_stream_id;
	this->version_number = version_number;
	this->current_next_indicator = current_next_indicator;
	this->section_number = section_number;
	this->last_section_number = last_section_number;
}

PAT::~PAT() {}

unsigned int PAT::getTableId() {
	return table_id;
}
unsigned char PAT::getSectionSyntax() {
	return section_syntax_indicator;
}
unsigned char PAT::getSectionLength() {
	return section_length;
}
unsigned char PAT::getTransportStreamId() {
	return transport_stream_id;
}

unsigned int PAT::getVersionNumber() {
	return version_number;
}
unsigned char PAT::getCurrentNextIndicator() {
	return current_next_indicator;
}
unsigned int PAT::getSectionNumber() {
	return section_number;
}
unsigned int PAT::getLastSectionNumber() {
	return last_section_number;
}