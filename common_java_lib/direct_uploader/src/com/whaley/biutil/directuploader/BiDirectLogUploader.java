package com.whaley.biutil.directuploader;

import com.whaley.biutil.BiLogUploaderBase;
import com.whaley.biutil.IBiLog;
import com.whaley.biutil.IBiLogUploader;

import com.helios.middleware.bi.HeliosBIManager;
import com.helios.middleware.bi.LogUrl;
import com.helios.middleware.bi.Strategy;

/**
 * Created by wanglei on 2016/7/29.
 */
public class BiDirectLogUploader extends BiLogUploaderBase{
    private Strategy MapStrategy(int s) {
        switch (s) {
        case IBiLogUploader.STRATEGY_DEFAULT:
            return Strategy.DEFAULT;
        case IBiLogUploader.STRATEGY_NO_CACHE:
            return Strategy.NO_CACHE;
        case IBiLogUploader.STRATEGY_UPLOAD_NOW:
            return Strategy.UPLOAD_NOW;
        default:
            return Strategy.DEFAULT;
        }
    }

    @Override
    public void Submit(IBiLog biLog) {
        Submit(biLog, IBiLogUploader.STRATEGY_DEFAULT);
    }

    @Override
    public void Submit(IBiLog biLog, int strategy) {
        if(!checkBeforeUpload(strategy)) return;
        strategy &= ~STRATEGY_SYSTEM_MASK;

        HeliosBIManager.getInstance().uploadLog(LogUrl.TV_ROMLOG,
                MapStrategy(strategy), biLog.GetString());
    }
}
