/*
 * Yuchuan Sun
 * Version 1.0
 * Date 2016-8-5
 * BiLog common module that is used by native code
*/

#define LOG_TAG "BiLogPair"
#include <utils/Log.h>
#include <fcntl.h>

#include "bistartendlog.h"
#include "bilogpair.h"

BiLogPair::BiLogPair(const char *caseId):
    mUuid(NULL),
    mCaseId(NULL)
{
    ALOGI("constructor");
    mUuid = (char *)malloc(37*sizeof(char));
    if(NULL == mUuid)
        ALOGE("malloc mUuid fail\n");
    else {
        int fd = open("/proc/sys/kernel/random/uuid", O_RDONLY);
        if(fd >= 0)
        {
            read(fd,mUuid,36);
            mUuid[36] = 0;
            close(fd);
        } else {
            ALOGE("get random fail\n");
        }
    }
    mCaseId = caseId;
}

BiLogPair::~BiLogPair()
{
    ALOGI("destructor");
    mCaseId = NULL;
    if(mUuid != NULL)
        free(mUuid);
    mUuid = NULL;
}

android::sp<IBiLog> BiLogPair::CreateStartLog()
{
    if(mUuid != NULL)
        return new BiStartEndLog(mCaseId, mUuid, "start");
    else
        return NULL;
}

android::sp<IBiLog> BiLogPair::CreateEndLog()
{
    if(mUuid != NULL)
        return new BiStartEndLog(mCaseId, mUuid, "end");
    else
        return NULL;
}

