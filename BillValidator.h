#pragma once

#include "MDBDevice.h"

class BillValidator : public MDBDevice
{
public:
	BillValidator(MDBSerial &mdb);

	void Update(unsigned long cc_change);

	bool Reset();
	void Print();

	inline unsigned long GetCredit() { return m_credit; }
	inline void ClearCredit() { m_credit = 0; }

private:
	int poll();
	void setup();
	void security();
	void type(int bills[]);
	void stacker();
	void escrow(bool accept);
	void expansion();

	int ADDRESS = 0x30;
	int SECURITY = 0x02;
	int ESCROW = 0x05;
	int STACKER = 0x06;

	unsigned long m_credit;

	bool m_full = false;
	int m_bills_in_stacker;

	char m_bill_scaling_factor;
	char m_decimal_places;
	unsigned int m_stacker_capacity;
	unsigned int m_security_levels;
	char m_can_escrow;
	char m_bill_type_credit[16];
};