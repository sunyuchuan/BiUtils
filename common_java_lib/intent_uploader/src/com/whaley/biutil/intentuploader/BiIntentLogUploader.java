package com.whaley.biutil.intentuploader;

import android.content.Intent;
import android.app.ActivityThread;
import android.content.Context;
import android.util.Log;
import android.os.UserHandle;
import com.whaley.biutil.IBiLog;
import com.whaley.biutil.BiLogUploaderBase;
import com.whaley.biutil.IBiLogUploader;


/**
 * Created by wanglei on 2016/7/29.
 */
public class BiIntentLogUploader extends BiLogUploaderBase{
    private final static String TAG = "BiIntentLogUploader";
    private static final String BI_UPLOADLOG_ACTION =
        "com.helios.middleware.bi.action.UPLOADLOG";
    private static final String BI_UPLOADLOG_EXTRA_URL = "LogUrl";
    private static final String BI_UPLOADLOG_EXTRA_STRATEGY = "Strategy";
    private static final String BI_UPLOADLOG_EXTRA_LOG = "LogString";

    @Override
    public void Submit(IBiLog biLog)
    {
        Submit(biLog, IBiLogUploader.STRATEGY_DEFAULT);
    }

    @Override
    public void Submit(IBiLog biLog, int strategy) {
        if(!checkBeforeUpload(strategy)) return;
        strategy &= ~STRATEGY_SYSTEM_MASK;

        Context context = ActivityThread.currentApplication();
        Intent intent = new Intent(BI_UPLOADLOG_ACTION);
        try {
            intent.putExtra(BI_UPLOADLOG_EXTRA_URL, IBiLogUploader.LOG_URL);
            intent.putExtra(BI_UPLOADLOG_EXTRA_STRATEGY, strategy);
            intent.putExtra(BI_UPLOADLOG_EXTRA_LOG, biLog.GetString());
            Log.i(TAG, "intent(" + biLog.GetString() + ")");
            context.sendBroadcastAsUser(intent, UserHandle.OWNER,
                android.Manifest.permission.READ_PHONE_STATE);
            //context.sendBroadcast(intent);
        } catch (Exception e) {
            Log.e(TAG, "ex: " + e);
        }
    }
}
