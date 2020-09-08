/*
 * Yuchuan Sun
 * Version 1.0
 * Date 2016-8-5
 * BiLog common module that is used by native code
*/

#define LOG_TAG "BiLogUploaderFactory"
#include <utils/Log.h>

#include "biloguploaderfactory.h"
#include "biintentloguploader.h"

BiLogUploaderFactory::BiLogUploaderFactory()
{
    ALOGI("constructor");
}

BiLogUploaderFactory::~BiLogUploaderFactory()
{
    ALOGI("destructor");
}

android::sp<IBiLogUploader> BiLogUploaderFactory::CreateBiLogUploader()
{
    return new android::BiIntentLogUploader();
}

