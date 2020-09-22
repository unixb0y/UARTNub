//
//  kern_start.cpp
//  UARTNub
//
//  Copyright © 2020 unixb0y. All rights reserved.
//

#include <Headers/kern_api.hpp>
#include <Headers/plugin_start.hpp>

#include "uartnub.hpp"

static MyNub uartnub;

static const char *bootargOff[] {
	"-uartnuboff"
};

static const char *bootargDebug[] {
	"-uartnubdbg"
};

static const char *bootargBeta[] {
	"-uartnubbeta"
};

PluginConfiguration ADDPR(config) {
	xStringify(PRODUCT_NAME),
	parseModuleVersion(xStringify(MODULE_VERSION)),
	LiluAPI::AllowNormal,
	bootargOff,
	arrsize(bootargOff),
	bootargDebug,
	arrsize(bootargDebug),
	bootargBeta,
	arrsize(bootargBeta),
	KernelVersion::MountainLion,
	KernelVersion::Catalina,
	[]() {
		uartnub.init();
	}
};
