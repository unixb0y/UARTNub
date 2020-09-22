//
//  uartnub.cpp
//  UARTNub
//
//  Copyright © 2020 unixb0y. All rights reserved.
//

#include <Headers/kern_api.hpp>
#include <Headers/plugin_start.hpp>

#include "uartnub.hpp"

MyNub *MyNub::instance = nullptr;

bool MyNub::init() {
    instance = this;
    
    IOLog("Initializing");
    DBGLOG("uartnub", "Initializing");
    return true;
}

bool MyNub::start(IOService *provider) {
    doRegisterService();
    return true;
}
