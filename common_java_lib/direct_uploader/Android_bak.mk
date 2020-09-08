LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_MODULE := com.whaley.biutil.direct-uploader
LOCAL_MODULE_TAGS := optional

#build bi-utils library
LOCAL_SRC_FILES := $(call all-java-files-under, src)

LOCAL_STATIC_JAVA_LIBRARIES := \
    middlewarebiapi

#LOCAL_JAVA_LIBRARIES := \
#    com.whaley.biutil.common

LOCAL_MODULE_CLASS := JAVA_LIBRARIES
LOCAL_JAVACFLAGS := -Xlint:all
include $(BUILD_JAVA_LIBRARY)



#clear all local vars
include $(CLEAR_VARS)

LOCAL_PREBUILT_STATIC_JAVA_LIBRARIES := middlewarebiapi:libs/middleware-bi.jar

include $(BUILD_MULTI_PREBUILT)
