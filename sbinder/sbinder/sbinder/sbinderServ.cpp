#define LOG_TAG     "sbinder_serv"

#include <binder/IPCThreadState.h>
#include <sbinder/sbinderServ.h>

using namespace sita_android;

int sbinder_start() {
    sp<ProcessState> proc(ProcessState::self());
    ProcessState::self()->startThreadPool();
    ALOGV("ProcessState::self()->startThreadPool();");
    return 0;
}

int sbinder_serv()
{
    sp<ProcessState> proc(ProcessState::self());
    ProcessState::self()->startThreadPool();
    IPCThreadState::self()->joinThreadPool();
    ALOGV("IPCThreadState::self()->joinThreadPool();");
    return 0;
}
