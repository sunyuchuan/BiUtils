/*
 * Yuchuan Sun
 * Version 1.0
 * Date 2016-8-5
 * BiLog common module that is used by native code
*/

#ifndef I_BI_LOG_H
#define I_BI_LOG_H
#include <utils/RefBase.h>

class IBiLog:public android::RefBase
{
public:
    IBiLog(){}
    virtual ~IBiLog(){}
    virtual void PushParameter(const char *name, const char *value) = 0;
    virtual const char * GetString() = 0;
};

#endif

