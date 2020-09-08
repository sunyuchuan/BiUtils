/*
 * Yuchuan Sun
 * Version 1.0
 * Date 2016-8-5
 * BiLog common module that is used by native code
*/

#ifndef BI_LOG_FACTORY_H
#define BI_LOG_FACTORY_H
#include "ibilog.h"
#include "ibilogpair.h"
#include <utils/RefBase.h>

class BiLogFactory:public android::RefBase
{
public:
    BiLogFactory();
    ~BiLogFactory();
    static android::sp<IBiLog> CreateLog(const char* caseId);
    static android::sp<IBiLogPair> CreateLogPair(const char* caseId);
private:

};

#endif

