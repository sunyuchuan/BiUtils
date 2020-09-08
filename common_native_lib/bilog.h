/*
 * Yuchuan Sun
 * Version 1.0
 * Date 2016-8-5
 * BiLog common module that is used by native code
*/

#ifndef BI_LOG_H
#define BI_LOG_H
#include "ibilog.h"
#include "json/json.h"

class BiLog:public IBiLog
{
public:
    BiLog(const char *logType);
    ~BiLog();
    void PutHeader(const char *name, const char *value);
    void PutHeader(const char * name, long long value);
    virtual void PushParameter(const char *name, const char *value);
    virtual const char * GetString();

private:
    Json::Value * mLogHeader;
    Json::Value * mParam;
    Json::Value * mParams;
};

#endif

