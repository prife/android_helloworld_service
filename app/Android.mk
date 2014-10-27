LOCAL_PATH := $(call my-dir)

#build server
include $(CLEAR_VARS)

LOCAL_SRC_FILES := main_helloworldservice.cpp

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../include

LOCAL_SHARED_LIBRARIES := libutils \
						  libbinder \
                          libhelloworld \
						  liblog

LOCAL_MODULE := helloworldservice
include $(BUILD_EXECUTABLE)

#build client
include $(CLEAR_VARS)

LOCAL_SRC_FILES := main_helloworldclient.cpp

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../include

LOCAL_SHARED_LIBRARIES := libutils \
						  libbinder \
                          libhelloworld \
						  liblog

LOCAL_MODULE := helloworldclient

include $(BUILD_EXECUTABLE)
