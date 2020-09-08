/*
 * Yuchuan Sun
 * Version 1.0
 * Date 2016-8-5
 * BiLog common module that is used by native code
*/

#ifndef BI_LOG_UPLOADER_BASE_H
#define BI_LOG_UPLOADER_BASE_H
#include "ibiloguploader.h"
#include "ibilog.h"

class BiLogUploaderBase:public IBiLogUploader
{
public:
    BiLogUploaderBase(){mLogUrl=NULL;mStrategy=0;}
    ~BiLogUploaderBase(){}
    virtual void Submit(const android::sp<IBiLog>& biLog)=0;
    virtual void Submit(const android::sp<IBiLog>& biLog, int strategy)=0;

    char * mLogUrl;
    int mStrategy;
};

#endif

