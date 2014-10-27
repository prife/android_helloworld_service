#include <binder/Parcel.h>
#include "BpHelloWorldService.h"
#include <utils/Log.h>

namespace android {
status_t BpHelloWorldService::helloworld(const char* str) {
    Parcel data, reply;
    data.writeInterfaceToken(IHelloWorldService::getInterfaceDescriptor());
    data.writeCString(str);
    status_t status = remote()->transact(1, data, &reply);
    if (status != NO_ERROR) {
        ALOGE("print helloworld error: %s", strerror(-status));
    } else {
        status = reply.readInt32();
    }

    return status;
}

BpHelloWorldService::BpHelloWorldService(const sp<IBinder>& impl)
    :BpInterface<IHelloWorldService>(impl)
{
}

}; //namespace android
