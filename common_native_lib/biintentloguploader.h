/*
 * Yuchuan Sun
 * Version 1.0
 * Date 2016-8-5
 * BiLog common module that is used by native code
*/

#ifndef BI_INTENT_LOG_UPLOADER_H
#define BI_INTENT_LOG_UPLOADER_H
#include <binder/IServiceManager.h>
#include <binder/Parcel.h>
#include "biloguploaderbase.h"
#include "ibilog.h"

namespace android {
#define BROADCAST_INTENT_TRANSACTION  ((IBinder::FIRST_CALL_TRANSACTION)+13)

class BiIntentLogUploader:public BiLogUploaderBase
{
public:
    BiIntentLogUploader();
    ~BiIntentLogUploader();
    virtual void Submit(const android::sp<IBiLog>& biLog);
    virtual void Submit(const android::sp<IBiLog>& biLog, int strategy);

private:
    bool checkBeforeUpload(int strategy);
    sp<IBinder> am;
};

}
#endif

