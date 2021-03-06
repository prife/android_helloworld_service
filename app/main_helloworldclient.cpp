#define LOG_TAG "HelloWorld_client"

#include <binder/IPCThreadState.h>
#include <binder/ProcessState.h>
#include <binder/IServiceManager.h>
#include <utils/Log.h>

#include "HelloWorldService.h"

int main(int argc, char *argv[])
{
    using namespace android;
	ALOGE("Hello client is now starting");

    sp<IHelloWorldService> shw;
#if 0
    sp<IServiceManager> sm = defaultServiceManager();
    sp<IBinder> binder;

    do {
        binder = sm->getService(String16("helloworld"));
        if (binder != 0)
                break;
        ALOGW("HelloWorld not published, waiting...");
        usleep(500000); // 0.5 s
    } while(true);

    //ALOGI("sm: %u binder: %u", sm, binder);

    //if (sDeathNotifier == NULL) {
    //    sDeathNotifier = new DeathNotifier();
    //}
    //binder->linkToDeath(sDeathNotifier);
    //sMediaPlayerService = interface_cast<IMediaPlayerService>(binder);

	ALOGE("Hello client is now trying");

    shw = interface_cast<IHelloWorldService>(binder);
#else
    if (getService<IHelloWorldService>(String16("helloworld"), &shw) == NAME_NOT_FOUND)
    {
        ALOGE("cann't found remote service server!");
        return -1;
    }
#endif
    shw->helloworld("hello, world");

	ALOGE("Hello client is now exiting");

	return(0);
}

