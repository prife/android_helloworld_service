#ifndef _HELLOWORLDSERVICE_H_
#define _HELLOWORLDSERVICE_H_
#include <binder/IInterface.h>

namespace android {

class IHelloWorldService: public IInterface {
public:
    DECLARE_META_INTERFACE(HelloWorldService)
    virtual status_t helloworld(const char *str) = 0;
};

};//namespace android

#endif
