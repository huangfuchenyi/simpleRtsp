#ifndef _TCPSOCKET_H_
#define _TCPSOCKET_H_
#define SOCKET_FD int
class TcpSocket
{
public:
	TcpSocket(SOCKET_FD sockfd=-1);
	virtual ~TcpSocket();
	SOCKET_FD Create();
	SOCKET_FD Accept();
	SOCKET_FD GetSocket() const { return sockfd_; }
	
	bool Bind(std::string ip, uint16_t port);
	bool Listen(int ConntMax);
    bool Connect(std::string ip, uint16_t port, int timeout = 0);
    void Close();
    void ShutdownWrite();
    
private:
	SOCKET_FD sockfd_;
};
#endif