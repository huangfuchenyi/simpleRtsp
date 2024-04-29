#include "tcpsocket.h"
TcpSocket::TcpSocket(SOCKET_FD sockfd)
	sockfd_(sockfd)
{
	printf("create TcpSocket server\n");
}
SOCKET_FD TcpSocket::Create()
{
	sockfd_ = ::socket(AF_INET, SOCK_STREAM, 0);
	return sockfd_;
}
SOCKET_FD TcpSocket::Accept()
{
	struct sockaddr_in addr = {0};
	socklen_t addrlen = sizeof addr;

	SOCKET_FD socket_fd = ::accept(sockfd_, (struct sockaddr*)&addr, &addrlen);
	return socket_fd;
}
bool TcpSocket::Bind(std :: string ip, uint16_t port)
{
	struct sockaddr_in addr = {0};			  
	addr.sin_family = AF_INET;		  
	addr.sin_addr.s_addr = inet_addr(ip.c_str()); 
	addr.sin_port = htons(port);  

	if(::bind(sockfd_, (struct sockaddr*)&addr, sizeof(addr)) == SOCKET_ERROR) {
		LOG_DEBUG(" <socket=%d> bind <%s:%u> failed.\n", sockfd_, ip.c_str(), port);
		return false;
	}

	return true;
}
bool TcpSocket::Listen(int ConntMax)
{
	if(::listen(sockfd_, ConntMax) == SOCKET_ERROR) {
		LOG_DEBUG("<socket=%d> listen failed.\n", sockfd_);
		return false;
	}

	return true;
}
bool TcpSocket::Connect(std :: string ip, uint16_t port, int timeout = 0)
{ 
	if(!connect(sockfd_, ip, port, timeout)) {
		LOG_DEBUG("<socket=%d> connect failed.\n", sockfd_);
		return false;
	}

	return true;
}
void TcpSocket::Close()
{
	::close(sockfd_);
	sockfd_ = -1;
}
void TcpSocket::ShutdownWrite()
{
	shutdown(sockfd_, SHUT_WR);
	sockfd_ = -1;
}

