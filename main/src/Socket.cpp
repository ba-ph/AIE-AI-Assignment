#include "Socket.h"
#include <iostream>

class Socket
{
public:

	Socket();
	~Socket();

		bool Open(unsigned short port);
		void Close();
		bool IsOpen() const;
		bool Send(const Address & destination, const void * data, int size);
		int Receive(Address & sender, void * data, int size);

private:
	int socket;
};
