/*
 * Copyright (C) 2009 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */
#include <string.h>
#include <jni.h>
#include <curl/curl.h>
#include <string>
/* This is a trivial JNI example where we use a native method
 * to return a new VM String. See the corresponding Java source
 * file located at:
 *
 *   apps/samples/hello-jni/project/src/com/example/hellojni/HelloJni.java
 */
#include "log.h"
#include "sitemanager.h"
#ifdef __cplusplus
using namespace std;
extern "C"{
#endif
#include "utils/stringutil.h"
JNIEXPORT jstring changeSite(JNIEnv *env, jobject jobj, jstring initdata){

}

JNIEXPORT jstring translation(JNIEnv *env, jobject jobj, jstring word){
    auto wordstr = jstringTostring(env, word);
    LOGD("function translation params is %s\n", wordstr.c_str());
    auto site = SiteManager::Instance()->site();
    LOGD("site name %s\n", site->getName().c_str());
    auto url = site->composeUrl(wordstr);
    LOGD("Get url: %s\n", url.c_str());
    auto content = site->getPage(url);
    //LOGD("content is: %s\n", content.c_str());
    auto ret = site->parse(content);
    LOGD("Get ret: %s\n", ret.c_str());
    return env->NewStringUTF(ret.c_str());
}

JNIEXPORT jstring translations(JNIEnv *env,jobject jobj, jstring sentence){
	return env->NewStringUTF("This is dynamic string\n ");
}


static const JNINativeMethod gMethods[]={
	{"translations", "(Ljava/lang/String;)Ljava/lang/String;", (jstring)translations},
	{"translation", "(Ljava/lang/String;)Ljava/lang/String;", (jstring)translation}
	
};

jint JNI_OnLoad(JavaVM* vm, void* reserved){
    JNIEnv* env = NULL;
    jint result = -1;
    if(vm->GetEnv((void **)&env, JNI_VERSION_1_4) != JNI_OK)
    {
        LOGD("JNI_VERSION_1_4 error\n");
    }
    static const char* const className = "com/cnlxu/network/HttpProxy";
    jclass clazz = env->FindClass(className);
    env->RegisterNatives(clazz,
        gMethods,sizeof(gMethods)/sizeof(gMethods[0]));
    return JNI_VERSION_1_4;
}

#ifdef __cplusplus
}
#endif