//
// Created by spc on 2016/10/28.
//

#include "com_example_spc_mmfpeghello_NativeMethods.h"
#include <android/log.h>
#include <string.h>
#include <jni.h>
#include <stdio.h>
#include "libavcodec/avcodec.h"
#include "libavformat/avformat.h"
#include "libavfilter/avfilter.h"


#define TAG "myDemo-jni" // 这个是自定义的LOG的标识
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,TAG ,__VA_ARGS__) // 定义LOGD类型
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,TAG ,__VA_ARGS__) // 定义LOGI类型
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN,TAG ,__VA_ARGS__) // 定义LOGW类型
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,TAG ,__VA_ARGS__) // 定义LOGE类型
#define LOGF(...) __android_log_print(ANDROID_LOG_FATAL,TAG ,__VA_ARGS__) // 定义LOGF类型


JNIEXPORT jstring JNICALL Java_com_example_spc_mmfpeghello_NativeMethods_helloWorld        (JNIEnv *env, jobject obj)
{
    char info[10000] = {0};
    sprintf(info, "%s\n", avcodec_configuration());
    return (*env)->NewStringUTF(env, info);
}


JNIEXPORT jstring JNICALL Java_com_example_spc_mmfpeghello_NativeMethods_urlprotocolinfo
        (JNIEnv *env, jobject obj)
{
    char info[40000]={0};
    av_register_all();

    struct URLProtocol *pup = NULL;
    //Input
    struct URLProtocol **p_temp = &pup;
    avio_enum_protocols((void **)p_temp, 0);
    while ((*p_temp) != NULL){
        sprintf(info, "%s[In][%10s]\n", info, avio_enum_protocols((void **)p_temp, 0));
    }
    pup = NULL;
    //Output
    avio_enum_protocols((void **)p_temp, 1);
    while ((*p_temp) != NULL){
        sprintf(info, "%s[Out][%10s]\n", info, avio_enum_protocols((void **)p_temp, 1));
    }

    //LOGE("%s", info);
    return (*env)->NewStringUTF(env, info);

}


JNIEXPORT jstring JNICALL Java_com_example_spc_mmfpeghello_NativeMethods_avformatinfo
        (JNIEnv *env, jobject obj)
{

    char info[40000] = { 0 };

    av_register_all();

    AVInputFormat *if_temp = av_iformat_next(NULL);
    AVOutputFormat *of_temp = av_oformat_next(NULL);
    //Input
    while(if_temp!=NULL){
        sprintf(info, "%s[In ][%10s]\n", info, if_temp->name);
        if_temp=if_temp->next;
    }
    //Output
    while (of_temp != NULL){
        sprintf(info, "%s[Out][%10s]\n", info, of_temp->name);
        of_temp = of_temp->next;
    }
    //LOGE("%s", info);
    return (*env)->NewStringUTF(env, info);

}


 JNIEXPORT jstring     JNICALL Java_com_example_spc_mmfpeghello_NativeMethods_avcodecinfo
                         (JNIEnv *env, jobject obj)
  {
      char info[40000] = { 0 };

       av_register_all();

      AVCodec *c_temp = av_codec_next(NULL);

       while(c_temp!=NULL){
        if (c_temp->decode!=NULL){
                 sprintf(info, "%s[Dec]", info);
             }
             else{
                 sprintf(info, "%s[Enc]", info);
             }
             switch (c_temp->type){
                 case AVMEDIA_TYPE_VIDEO:
                     sprintf(info, "%s[Video]", info);
                     break;
                 case AVMEDIA_TYPE_AUDIO:
                     sprintf(info, "%s[Audio]", info);
                     break;
                 default:
                     sprintf(info, "%s[Other]", info);
                     break;
             }
             sprintf(info, "%s[%10s]\n", info, c_temp->name);


             c_temp=c_temp->next;
         }
         //LOGE("%s", info);

         return (*env)->NewStringUTF(env, info);

     }


 JNIEXPORT jstring     JNICALL Java_com_example_spc_mmfpeghello_NativeMethods_avfilterinfo
                         (JNIEnv *env, jobject obj)
 {
  char info[40000] = { 0 };
         avfilter_register_all();
         AVFilter *f_temp = (AVFilter *)avfilter_next(NULL);
         while (f_temp != NULL){
           sprintf(info, "%s[%10s]\n", info, f_temp->name);
             f_temp = f_temp->next;
                }
        return (*env)->NewStringUTF(env, info);

 }
