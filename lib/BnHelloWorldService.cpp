#include "BnHelloWorldService.h"
#include <binder/Parcel.h>

namespace android {

status_t BnHelloWorldService::onTransact(uint32_t code,
                                         const Parcel &data,
                                         Parcel *reply,
                                         uint32_t flags)
{
    //LOGE("OnTransact(%u,%u)", code, flags);
    switch(code) {
    case 1: {
        CHECK_INTERFACE(IHelloWorldService, data, reply);
        const char *str = data.readCString();
        reply->writeInt32(helloworld(str));
        return NO_ERROR;
    } break;
    default:
        return BBinder::onTransact(code, data, reply, flags);
    }

    return NO_ERROR;
}

};
