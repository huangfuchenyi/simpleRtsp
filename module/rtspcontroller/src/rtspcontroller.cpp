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
}