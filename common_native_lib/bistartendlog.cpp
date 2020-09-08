/*
 * Yuchuan Sun
 * Version 1.0
 * Date 2016-8-5
 * BiLog common module that is used by native code
*/

#define LOG_TAG "BiStartEndLog"
#include "bistartendlog.h"
#include <utils/Log.h>

BiStartEndLog::BiStartEndLog(const char *caseId,
    const char *uuid, const char *status):
    BiLog("start_end")
{
    ALOGI("constructor");
    PutHeader("status", status);
    PutHeader("actionId", caseId);
    PutHeader("uuid", uuid);
}

BiStartEndLog::~BiStartEndLog()
{
    ALOGI("destructor");
}

