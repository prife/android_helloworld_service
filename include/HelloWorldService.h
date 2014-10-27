#ifndef HELLOWORLD_SERVICE_H
#define HELLOWORLD_SERVICE_H

#include <binder/Parcel.h>
#include "BnHelloWorldService.h"

namespace android {
class HelloWorldService: public BnHelloWorldService {
public:
    static void instantiate();
    virtual status_t helloworld(const char* str);
    status_t onTransact(uint32_t code,
                        const Parcel& data,
                        Parcel* reply,
                        uint32_t flags);
    virtual ~HelloWorldService();
private:
    HelloWorldService();

};

};

#endif //HELLOWORLD_SERVICE_H
