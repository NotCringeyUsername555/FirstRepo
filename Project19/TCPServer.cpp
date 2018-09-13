#include "TCPServer.h"
TCPServ::TCPServ() {
	WSAData ws;
	WSAStartup(MAKEWORD(2, 2), &ws);
}
void TCPServ::createSock(int port) {
	_listening = socket(AF_INET, SOCK_STREAM, 0);
	sockaddr_in addr;
	ZeroMemory(&addr, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);
	addr.sin_addr.S_un.S_addr = INADDR_ANY;
	bind(_listening, (sockaddr *)&addr, sizeof(addr));
	listen(_listening, 10);
}
SOCKET TCPServ::listenFor() {
	SOCKET ret = accept(_listening, NULL, NULL);
	return ret;
}
TCPServ::~TCPServ() {
	WSACleanup();
}