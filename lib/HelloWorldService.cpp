#include <binder/IServiceManager.h>
#include <binder/IPCThreadState.h>
#include <utils/Log.h>
#include "BnHelloWorldService.h"
#include "HelloWorldService.h"

namespace android {

void HelloWorldService::instantiate() {
	defaultServiceManager()->addService(
        String16("helloworld"), new HelloWorldService());
}

HelloWorldService::HelloWorldService()
{
    ALOGE("HelloWorldService created");
}

HelloWorldService::~HelloWorldService()
{
    ALOGE("HelloWorldService destroyed");
}

status_t HelloWorldService::helloworld(const char*str)
{
    ALOGE("hello: %s\n", str);
    printf("hello: %s\n", str);
    return NO_ERROR;
}

status_t HelloWorldService::onTransact(uint32_t code,
                                       const Parcel& data,
                                       Parcel* reply,
                                       uint32_t flags)
{
    return BnHelloWorldService::onTransact(code, data, reply, flags);
}

}; //namespace android
