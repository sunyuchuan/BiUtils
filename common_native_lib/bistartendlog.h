/*
 * Yuchuan Sun
 * Version 1.0
 * Date 2016-8-5
 * BiLog common module that is used by native code
*/

#ifndef BI_START_END_LOG_H
#define BI_START_END_LOG_H
#include "bilog.h"

class BiStartEndLog:public BiLog
{
public:
    BiStartEndLog(const char *caseId, const char *uuid, const char *status);
    ~BiStartEndLog();
private:
    char * Uuid;
    char * Status;
};

#endif
