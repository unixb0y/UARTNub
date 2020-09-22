//
//  uartnub.hpp
//  UARTNub
//
//  Copyright © 2020 unixb0y. All rights reserved.
//

#ifndef uartnub_hpp
#define uartnub_hpp

#include <sys/kernel_types.h>
#include <sys/kern_control.h>

#include <Headers/kern_patcher.hpp>
#include <IOKit/serial/IORS232SerialStreamSync.h>

#define kThisKextID "com.unixb0y.UARTNub"

struct ClientInfo {
    u_int32_t sc_unit = 0;
    bool connected = false;
};

class MyNub: IORS232SerialStreamSync {
public:
    MyNub() = default;
    
    bool init() override;
    bool start(IOService *provider) override;
    
    static void doRegisterService() {
        if (instance) {
            instance->registerService();
        }
        else {
            PANIC("vsmc", "missing instance for service registration");
        }
    }

private:
    static MyNub *instance;
};

#endif /* uartnub_hpp */
