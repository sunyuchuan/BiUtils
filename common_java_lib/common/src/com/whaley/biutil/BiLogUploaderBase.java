package com.whaley.biutil;

import android.os.SystemProperties;
import android.util.Log;
/**
 * Created by wanglei on 2016/7/29.
 */
public abstract class BiLogUploaderBase implements IBiLogUploader{
    protected String mLogUrl = "";
    protected int mStrategy = 0;

    @Override
    public abstract void Submit(IBiLog biLog);

    @Override
    public abstract void Submit(IBiLog biLog, int strategy);

    protected final boolean checkBeforeUpload(int strategy) {
        if (((strategy & STRATEGY_SYSTEM_MASK) == STRATEGY_UPLOAD_USER) &&
                !("user".equals(SystemProperties.get("ro.build.type")))) {
            Log.i("BiLogUploader-java", "Upload strategy is User only, Don't upload");
            return false;
        }
        return true;
    }
}
