/*
 * Yuchuan Sun
 * Version 1.0
 * Date 2016-8-5
 * BiLog common module that is used by native code
*/

#define LOG_TAG "BiIntentLogUploader"
#include <utils/Log.h>
#include "biintentloguploader.h"
#include <cutils/properties.h>

static const char * bi_uploadlog_action = "com.helios.middleware.bi.action.UPLOADLOG";
static const char * bi_uploadlog_extra_url = "LogUrl";
static const char * bi_uploadlog_extra_strategy = "Strategy";
static const char * bi_uploadlog_extra_log = "LogString";

namespace android {

enum VALUE_TYPE
{
    VAL_NULL = -1,
    VAL_STRING = 0,
    VAL_INTEGER = 1,
    VAL_MAP = 2,
    VAL_BUNDLE = 3,
    VAL_PARCELABLE = 4,
    VAL_SHORT = 5,
    VAL_LONG = 6,
    VAL_FLOAT = 7,
    VAL_DOUBLE = 8,
    VAL_BOOLEAN = 9,
    VAL_CHARSEQUENCE = 10,
    VAL_LIST  = 11,
    VAL_SPARSEARRAY = 12,
    VAL_BYTEARRAY = 13,
    VAL_STRINGARRAY = 14,
    VAL_IBINDER = 15,
    VAL_PARCELABLEARRAY = 16,
    VAL_OBJECTARRAY = 17,
    VAL_INTARRAY = 18,
    VAL_LONGARRAY = 19,
    VAL_BYTE = 20,
    VAL_SERIALIZABLE = 21,
    VAL_SPARSEBOOLEANARRAY = 22,
    VAL_BOOLEANARRAY = 23,
    VAL_CHARSEQUENCEARRAY = 24,
};

BiIntentLogUploader::BiIntentLogUploader():
    am(NULL)
{
    ALOGI("constructor");
    sp<IServiceManager> sm = defaultServiceManager();
    if(sm != NULL)
        am = sm->checkService(String16("activity"));
    sm = NULL;
}

BiIntentLogUploader::~BiIntentLogUploader()
{
    ALOGI("destructor");
    am = NULL;
}

static void writeToParcelHeader(Parcel * data)
{
    data->writeInterfaceToken(String16("android.app.IActivityManager"));
    data->writeStrongBinder(NULL);
    data->writeString16(String16(bi_uploadlog_action));
    data->writeInt32(0);
    data->writeString16(NULL,0);
    data->writeInt32(0);
    data->writeString16(NULL,0);
    data->writeString16(NULL,0);
    data->writeInt32(0);
    data->writeInt32(0);
    data->writeInt32(0);
    data->writeInt32(0);
    data->writeInt32(-1);
}

static void writeToParcelBundle(Parcel * data, const android::sp<IBiLog>& biLog, int strategy)
{
    int lengthPos = data->dataPosition();
    data->writeInt32(-1);
    data->writeInt32(0x4C444E42); // 'B' 'N' 'D' 'L'
    int oldPos = data->dataPosition();
    { /* writeMapInternal */
        data->writeInt32(3);
      /*the first extra*/
        data->writeString16(String16(bi_uploadlog_extra_url));
        data->writeInt32(VAL_INTEGER);
        data->writeInt32(IBiLogUploader::log_url);
      /*the second extra*/
        data->writeString16(String16(bi_uploadlog_extra_strategy));
        data->writeInt32(VAL_INTEGER);
        data->writeInt32(strategy);
      /*the third extra*/
        data->writeString16(String16(bi_uploadlog_extra_log));
        data->writeInt32(VAL_STRING);
        data->writeString16(String16(biLog->GetString()));
    }
    int newPos = data->dataPosition();
    data->setDataPosition(lengthPos);
    data->writeInt32(newPos - oldPos);
    data->setDataPosition(newPos);
}

static void writeToParcelTail(Parcel * data)
{
    data->writeString16(NULL,0);
    data->writeStrongBinder(NULL);
    data->writeInt32(-1);
    data->writeString16(NULL,0);
    data->writeInt32(-1);
    data->writeString16(NULL,0);
    data->writeInt32(false);
    data->writeInt32(false);
    data->writeInt32(false);
    data->writeInt32(false);
}

void BiIntentLogUploader::Submit(const android::sp<IBiLog>& biLog)
{
    Submit(biLog, IBiLogUploader::strategy_default);
}

void BiIntentLogUploader::Submit(const android::sp<IBiLog>& biLog, int strategy)
{
    if(!checkBeforeUpload(strategy)) return;
    strategy &= ~strategy_system_mask;

    Parcel data, reply;
    writeToParcelHeader(&data);
    writeToParcelBundle(&data,biLog,strategy);
    writeToParcelTail(&data);
    if(am != NULL)
    {
        status_t ret = am->transact(BROADCAST_INTENT_TRANSACTION,data,&reply);
        if(ret == NO_ERROR)
        {
            int32_t exceptionCode = reply.readExceptionCode();
            if (!exceptionCode)
            {
                ALOGI("sendBroadcast succeed\n");
            } else {
                // An exception was thrown back; fall through to return failure
                ALOGE("sendBroadcast caught exception %d\n",exceptionCode);
            }
        }
    } else {
        ALOGE("am is NULL,sendBroadcast failed\n");
    }
}

bool BiIntentLogUploader::checkBeforeUpload(int strategy) {
    char buildType[PROPERTY_VALUE_MAX];
    property_get("ro.build.type", buildType, "user");
    if((strategy & strategy_system_mask) == strategy_upload_user
            && 0 != strcmp(buildType, "user")) {
        ALOGI("Upload strategy is ReleaseOnly(100), Don't upload");
        return false;
    }
    return true;
}

}
