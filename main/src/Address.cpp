#include "Address.h"



Address::Address()
{
	m_address = 0;
	m_port = 0;
}


Address::~Address()
{
}

Address::Address(unsigned char a, unsigned char b, unsigned char c, unsigned char d, unsigned short port)
{
	this->m_address = (a << 24) | (b << 16) | (c << 8) | d;
	this->m_port = port;
}

Address::Address(unsigned int address, unsigned short port)
{
	this->m_address = address;
	this->m_port = port;
}

unsigned int Address::GetAddress() const
{
	return m_address;
}

unsigned char Address::GetA() const
{
	return (unsigned char)(m_address >> 24);
}

unsigned char Address::GetB() const
{
	return (unsigned char)(m_address >> 16);
}

unsigned char Address::GetC() const
{
	return (unsigned char)(m_address >> 8);
}

unsigned char Address::GetD() const
{
	return (unsigned char)(m_address);
}

unsigned short Address::GetPort() const
{
	return m_port;
}