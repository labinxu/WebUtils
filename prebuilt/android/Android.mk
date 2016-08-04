LOCAL_PATHA := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE := curl_static
LOCAL_MODULE_FILENAME := curl
LOCAL_SRC_FILES := prebuilt/android/$(TARGET_ARCH_ABI)/libcurl.a
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATHA)/../../include
LOCAL_STATIC_LIBRARIES += ssl_static
LOCAL_STATIC_LIBRARIES += crypto_static
include $(PREBUILT_STATIC_LIBRARY)

include $(CLEAR_VARS)

LOCAL_MODULE := crypto_static
LOCAL_MODULE_FILENAME := crypto
LOCAL_SRC_FILES := prebuilt/android/$(TARGET_ARCH_ABI)/libcrypto.a
include $(PREBUILT_STATIC_LIBRARY)
#
LOCAL_MODULE := ssl_static
LOCAL_MODULE_FILENAME := ssl
LOCAL_SRC_FILES := prebuilt/android/$(TARGET_ARCH_ABI)/libssl.a
include $(PREBUILT_STATIC_LIBRARY)
