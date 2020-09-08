/*
 * Yuchuan Sun
 * Version 1.0
 * Date 2016-8-5
 * BiLog common module that is used by native code
*/

#ifndef BI_LOG_UPLOADER_FACTORY_H
#define BI_LOG_UPLOADER_FACTORY_H
#include "ibiloguploader.h"
#include <utils/RefBase.h>

class BiLogUploaderFactory:public android::RefBase
{
public:
    BiLogUploaderFactory();
    ~BiLogUploaderFactory();
    static android::sp<IBiLogUploader> CreateBiLogUploader();
private:

};

#endif

