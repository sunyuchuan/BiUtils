/*
 * Yuchuan Sun
 * Version 1.0
 * Date 2016-8-5
 * BiLog common module that is used by native code
*/

#define LOG_TAG "BiEventLog"
#include <utils/Log.h>

#include "bieventlog.h"

BiEventLog::BiEventLog(const char * caseId):
    BiLog("event")
{
    ALOGI("constructor");
    PutHeader("eventId",caseId);
}

BiEventLog::~BiEventLog()
{
    ALOGI("destructor");
}

