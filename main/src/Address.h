#pragma once
class Address
{
public:
	Address();
	Address(unsigned char a,
		    unsigned char b,
		    unsigned char c,
		    unsigned char d,
		    unsigned short port);
	Address(unsigned int address, unsigned short port);
	~Address();

	unsigned int GetAddress() const;
	unsigned char GetA() const;
	unsigned char GetB() const;
	unsigned char GetC() const;
	unsigned char GetD() const;
	unsigned short GetPort() const;


	bool operator == (const Address & other) const
	{
		return m_address == other.m_address && m_port == other.m_port;
	}

	bool operator != (const Address & other) const
	{
		return !(*this == other);
	}

private:
	unsigned int m_address;
	unsigned short m_port;
};

