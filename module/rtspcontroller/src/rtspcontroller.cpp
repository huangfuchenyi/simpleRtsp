#include "rtspcontroller.h"
RtspController::RtspController()
	:psocketserver_(NULL)
{
	printf("create RtspController \n");
}
bool RtspController::Create()
{
	psocketserver_ = new TcpSocket(-1);
	psocketserver_->Create();
	psocketserver_->Bind("127.0.0.0",8554);
	psocketserver_->Listen(10);
}
int RtspController::Run()
{
	SOCKET_FD socket_fd  = psocketserver_->Accept();
	if (socket_fd != INVALID_SOCKET){
		RtspSession* pSession = new RTSPSession(sockAccpet, nMediaPortMin_, nSetTrackNumTimeOutInterval_, nSDPTimeOutInterval_);//获取客户端地址信息
		mEstablishingSession.push_back(pSession);
	}

}