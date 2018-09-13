#pragma once
#include <WS2tcpip.h>
#include <string>
#pragma comment (lib, "ws2_32.lib")
class TCPServ {
public:
	TCPServ();
	~TCPServ();
	void createSock(int port);
	SOCKET listenFor();
private :
	SOCKET _listening;

};