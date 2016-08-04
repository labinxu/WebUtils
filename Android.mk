# Copyright (C) 2009 The Android Open Source Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
LOCAL_PATH := $(call my-dir)
include $(LOCAL_PATH)/prebuilt/android/Android.mk
include $(LOCAL_PATH)/external/tinyhtml/Android.mk
include $(CLEAR_VARS)
LOCAL_MODULE    := dict-jni
LOCAL_SRC_FILES := dict-jni.cpp httpclient.cpp sitemanager.cpp site.cpp \
                    dictyoudao.cpp stringutil.cpp
$(warning $(LOCAL_PATHA))                   
LOCAL_C_INCLUDES := $(LOCAL_PATH)/external/tinyhtml 
LOCAL_LDLIBS := -llog -lz
LOCAL_STATIC_LIBRARIES := tinyhtml curl_static crypto_static ssl_static

include $(BUILD_SHARED_LIBRARY)
