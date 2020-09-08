/*
 * Yuchuan Sun
 * Version 1.0
 * Date 2016-8-5
 * BiLog common module that is used by native code
*/

#ifndef I_BI_LOG_UPLOADER_H
#define I_BI_LOG_UPLOADER_H
#include "ibilog.h"
#include <utils/RefBase.h>

// Refer to http://wiki.moretv.cn/wiki/pj/backend/bi/middleware-bi-api
class IBiLogUploader:public android::RefBase
{
public:
    IBiLogUploader(){}
    virtual ~IBiLogUploader(){}
    virtual void Submit(const android::sp<IBiLog>& biLog) = 0;
    virtual void Submit(const android::sp<IBiLog>& biLog, int strategy) = 0;

    static const int log_url = 28;
    static const int strategy_default = 1;
    static const int strategy_no_cache = 2;
    static const int strategy_uploader_now = 3;

    // Defined by System Group to specify whether to upload depends on system
    // configuration
    static const int strategy_system_mask = 0xf0000000;
    static const int strategy_upload_user = 0x10000000;
    static const int strategy_upload_userdebug = 0x20000000;
    static const int strategy_upload_eng = 0x40000000;
};

#endif

