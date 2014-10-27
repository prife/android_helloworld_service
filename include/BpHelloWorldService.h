#ifndef BP_HELLOWORLD_SERVICE_H
#define BP_HELLOWORLD_SERVICE_H

#include <binder/Parcel.h>
#include "IHelloWorldService.h"

namespace android {
class BpHelloWorldService: public BpInterface<IHelloWorldService> {
public:
    BpHelloWorldService (const sp<IBinder>& impl);
    virtual status_t helloworld(const char* str);
};

};

#endif //BP_HELLOWORLD_SERVICE_H
