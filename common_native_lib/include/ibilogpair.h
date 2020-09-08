/*
 * Yuchuan Sun
 * Version 1.0
 * Date 2016-8-5
 * BiLog common module that is used by native code
*/

#ifndef I_BI_LOG_PAIR_H
#define I_BI_LOG_PAIR_H
#include <utils/RefBase.h>

class IBiLogPair:public android::RefBase
{
public:
    IBiLogPair(){}
    virtual ~IBiLogPair(){}
    virtual android::sp<IBiLog> CreateStartLog() = 0;
    virtual android::sp<IBiLog> CreateEndLog() = 0;
};
#endif
