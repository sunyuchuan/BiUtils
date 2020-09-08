/*
 * Yuchuan Sun
 * Version 1.0
 * Date 2016-8-5
 * BiLog common module that is used by native code
*/

#define LOG_TAG "BiLogFactory"
#include <utils/Log.h>

#include "bieventlog.h"
#include "bilogpair.h"
#include "bilogfactory.h"

BiLogFactory::BiLogFactory()
{
    ALOGI("constructor");
}

BiLogFactory::~BiLogFactory()
{
    ALOGI("destructor");
}

android::sp<IBiLog> BiLogFactory::CreateLog(const char * caseId)
{
    return new BiEventLog(caseId);
}

android::sp<IBiLogPair> BiLogFactory::CreateLogPair(const char * caseId)
{
    return new BiLogPair(caseId);
}

