LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_SRC_FILES := \
	IHelloWorldService.cpp  \
	BnHelloWorldService.cpp \
	BpHelloWorldService.cpp \
	HelloWorldService.cpp

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../include

LOCAL_SHARED_LIBRARIES := libutils \
						  libbinder \
						  liblog

LOCAL_MODULE := libhelloworld
include $(BUILD_SHARED_LIBRARY)
