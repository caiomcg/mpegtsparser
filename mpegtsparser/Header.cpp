#include "Header.h"

Header::Header() {}

Header::Header(unsigned char sync_byte, unsigned char transport_error, unsigned char payload, unsigned char transport_priority, unsigned char PID, unsigned char transport_scrambling, unsigned char adaptation_field, unsigned char continuity_counter, unsigned int associated){
	this->sync_byte = sync_byte;
	this->transport_error_indicator = transport_error;
	this->payload_unit_start_indicator = payload;
	this->transport_priority = transport_priority;
	this->PID = PID;
	this->transport_scrambling_control = transport_scrambling;
	this->adaptation_field_control = adaptation_field;
	this->continuity_counter = continuity_counter;
	this->associated = associated;
}

Header::~Header() {}

unsigned char Header::getSyncByte() {
	return sync_byte;
}
void Header::setSyncByte(unsigned char value) {
	sync_byte = value;
}

unsigned char Header::getTransportError() {
	return transport_error_indicator;
}
void Header::setTransportError(unsigned char value) {
	transport_error_indicator = value;
}

unsigned char Header::getPayload() {
	return payload_unit_start_indicator;
}
void Header::setPayload(unsigned char value) {
	payload_unit_start_indicator = value;
}

unsigned char Header::getTransportPriority() {
	return transport_priority;
}
void Header::setTransportPriority(unsigned char value) {
	transport_priority = value;
}

unsigned char Header::getPID() {
	return PID;
}
void Header::setPID(unsigned char value) {
	PID = value;
}

unsigned char Header::getTransportScrambling() {
	return transport_scrambling_control;
}
void Header::setTransportScrambling(unsigned char value) {
	transport_scrambling_control = value;
}

unsigned char Header::getAdaptationField() {
	return adaptation_field_control;
}
void Header::setAdaptationField(unsigned char value) {
	adaptation_field_control = value;
}

unsigned char Header::getContinuityCounter() {
	return continuity_counter;
}
void Header::setContinuityCounter(unsigned char value) {
	continuity_counter = value;
}