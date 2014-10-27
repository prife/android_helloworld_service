/*
 * HelloWorld Service driver.
 * Copyright (C) 2009 Michael Richardson <mcr@credil.org>
 *
 * Released under the terms of the file ../NOTICE
 */
#define LOG_TAG "HelloWorld_server"

#include <binder/IPCThreadState.h>
#include <binder/ProcessState.h>
#include <binder/IServiceManager.h>
#include <utils/Log.h>

#include "HelloWorldService.h"

int main(int argc, char *argv[])
{
    using namespace android;
	HelloWorldService::instantiate();
	ProcessState::self()->startThreadPool();
	ALOGI("Hello Service is now ready");

	IPCThreadState::self()->joinThreadPool();
	return(0);
}
