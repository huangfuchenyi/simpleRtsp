/*
** testFunc1.h
*/

#ifndef _RTSPCONTROLLER_H_
#define _RTSPCONTROLLER_H_
#include "tcpsocket.h"
class RtspController {
public:
	RtspController();
	virtual ~RtspController();
	bool Create();
	int Run();
private:
	TcpSocket *psocketserver_;
	
};


#endif