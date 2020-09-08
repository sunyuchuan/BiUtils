/*
 * Yuchuan Sun
 * Version 1.0
 * Date 2016-8-5
 * BiLog common module that is used by native code
*/

#include "logPrint.h"
#define LOG_TAG "BILog"
#include <utils/Log.h>
#include <sys/time.h>
#include <string.h>
#include <stdio.h>

#include "bilog.h"

static const char *log_version = "02";

BiLog::BiLog(const char *logType):
    mLogHeader(new Json::Value),
    mParam(new Json::Value),
    mParams(new Json::Value)
{
    ALOGI("constructor");
    struct timeval time;
    long long happenTime = 0;
    char strHappenTime[128] = {0};
    gettimeofday(&time,NULL);
    happenTime = ((long long)time.tv_sec*1000 + (long long)time.tv_usec/1000);
    snprintf(strHappenTime,sizeof(strHappenTime),"%lld",happenTime);

    PutHeader("logVersion",log_version);
    PutHeader("logType",logType);
    //PutHeader("happenTime",strHappenTime);
    PutHeader("happenTime",happenTime);
}

BiLog::~BiLog()
{
    ALOGI("destructor");
    if(mLogHeader)
        delete mLogHeader;
    mLogHeader = NULL;
    if(mParam)
        delete mParam;
    mParam = NULL;
    if(mParams)
        delete mParams;
    mParams = NULL;
}

void BiLog::PutHeader(const char * name, const char * value)
{
    (*(mLogHeader))[name] = value;
}

void BiLog::PutHeader(const char * name, long long value)
{
    (*(mLogHeader))[name] = value;
}

void BiLog::PushParameter(const char * name, const char * value)
{
    (*(mParam))[name] = value;
    //mParams.append(mParam);
}

const char * BiLog::GetString()
{
    (*(mLogHeader))["params"] = *(mParam);
    ALOGD("%s",mLogHeader->toStyledString().c_str());
    return mLogHeader->toStyledString().c_str();
}

