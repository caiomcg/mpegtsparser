#pragma once

class Header {
private:
	unsigned char sync_byte;
	unsigned char transport_error_indicator;
	unsigned char payload_unit_start_indicator;
	unsigned char transport_priority;
	unsigned char PID;
	unsigned char transport_scrambling_control;
	unsigned char adaptation_field_control;
	unsigned char continuity_counter;
	unsigned int associated;

public:
	Header();
	Header(unsigned char sync_byte, unsigned char transport_error, unsigned char payload, unsigned char transport_priority, unsigned char PID, unsigned char transport_scrambling, unsigned char adaptation_field, unsigned char continuity_counter, unsigned int associated);
	~Header();

	unsigned char getSyncByte();
	void setSyncByte(unsigned char value);

	unsigned char getTransportError();
	void setTransportError(unsigned char value);

	unsigned char getPayload();
	void setPayload(unsigned char value);

	unsigned char getTransportPriority();
	void setTransportPriority(unsigned char value);

	unsigned char getPID();
	void setPID(unsigned char value);

	unsigned char getTransportScrambling();
	void setTransportScrambling(unsigned char value);

	unsigned char getAdaptationField();
	void setAdaptationField(unsigned char value);

	unsigned char getContinuityCounter();
	void setContinuityCounter(unsigned char value);
};