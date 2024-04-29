/*
** testFunc1.h
*/

#ifndef _RTSPCONTROLLER_H_
#define _RTSPCONTROLLER_H_

class RtspController {
public:
	RtspController();
	virtual ~RtspController();
	bool Create();
private:
	TcpSocket *psocketserver_;
	
};


#endif