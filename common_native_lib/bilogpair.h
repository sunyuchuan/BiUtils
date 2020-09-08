/*
 * Yuchuan Sun
 * Version 1.0
 * Date 2016-8-5
 * BiLog common module that is used by native code
*/

#ifndef BI_LOG_PAIR_H
#define BI_LOG_PAIR_H
#include "ibilog.h"
#include "ibilogpair.h"

class BiLogPair:public IBiLogPair
{
public:
    BiLogPair(const char *caseId);
    ~BiLogPair();
    virtual android::sp<IBiLog> CreateStartLog();
    virtual android::sp<IBiLog> CreateEndLog();
private:
    char * mUuid;
    const char * mCaseId;
};

#endif
