LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := libbiutils

LOCAL_MODULE_TAGS := optional

LOCAL_C_INCLUDES := \
    $(LOCAL_PATH) \
    $(LOCAL_PATH)/include \
    external/jsoncpp/include \
    external/jsoncpp/include/json \
    external/jsoncpp/chromium-overrides/include \
    external/jsoncpp/src/lib_json

LOCAL_SHARED_LIBRARIES := \
    libc \
    liblog \
    libbinder \
    libutils \
    libcutils

LOCAL_STATIC_LIBRARIES := \
    libjsoncpp

LOCAL_MULTILIB := 32

LOCAL_SRC_FILES := \
    bilog.cpp \
    bilogfactory.cpp \
    bieventlog.cpp \
    bistartendlog.cpp \
    bilogpair.cpp \
    biloguploaderfactory.cpp \
    biintentloguploader.cpp

$(warning $(basename $(basename $(strip $(PLATFORM_VERSION)))))
ifeq ($(basename $(basename $(strip $(PLATFORM_VERSION)))),5)
include external/stlport/libstlport.mk
endif

include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)

LOCAL_MODULE := libbiutils

LOCAL_MODULE_TAGS := optional

LOCAL_C_INCLUDES := \
    $(LOCAL_PATH) \
    $(LOCAL_PATH)/include \
    external/jsoncpp/include \
    external/jsoncpp/include/json \
    external/jsoncpp/chromium-overrides/include \
    external/jsoncpp/src/lib_json

LOCAL_SHARED_LIBRARIES := \
    libc \
    liblog \
    libbinder \
    libutils \
    libcutils

LOCAL_STATIC_LIBRARIES := \
    libjsoncpp

LOCAL_MULTILIB := 64

LOCAL_SRC_FILES := \
    bilog.cpp \
    bilogfactory.cpp \
    bieventlog.cpp \
    bistartendlog.cpp \
    bilogpair.cpp \
    biloguploaderfactory.cpp \
    biintentloguploader.cpp

$(warning $(basename $(basename $(strip $(PLATFORM_VERSION)))))
ifeq ($(basename $(basename $(strip $(PLATFORM_VERSION)))),5)
include external/stlport/libstlport.mk
endif

include $(BUILD_SHARED_LIBRARY)
include $(call all-makefiles-under,$(LOCAL_PATH))

