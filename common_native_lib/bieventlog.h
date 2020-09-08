/*
 * Yuchuan Sun
 * Version 1.0
 * Date 2016-8-5
 * BiLog common module that is used by native code
*/

#ifndef BI_EVENT_LOG_H
#define BI_EVENT_LOG_H
#include "bilog.h"

class BiEventLog:public BiLog
{
public:
    BiEventLog(const char * caseId);
    ~BiEventLog();
};

#endif

